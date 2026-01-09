#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * The string is a "New Year string" if:
 * 1. "2026" is a substring OR
 * 2. "2025" is NOT a substring.
 */
int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // --- Condition 1: Minimum edits to include "2026" ---
    int edits_for_2026 = n;
    string target2026 = "2026";
    for (int i = 0; i <= n - 4; ++i) {
        int current_edits = 0;
        for (int j = 0; j < 4; ++j) {
            if (s[i + j] != target2026[j]) current_edits++;
        }
        edits_for_2026 = min(edits_for_2026, current_edits);
    }

    // --- Condition 2: Minimum edits to exclude "2025" ---
    string target2025 = "2025";
    // dp[i][state] = min cost for prefix length i with suffix matching target2025[0...state-1]
    vector<vector<int>> dp(n + 1, vector<int>(4, n + 1));
    dp[0][0] = 0;

    // Helper to find the next state after adding character 'c' to a suffix of length 'state'
    auto get_next_state = [&](int state, char c) {
        string cur = target2025.substr(0, state) + c;
        for (int len = min((int)cur.size(), 3); len >= 1; --len) {
            if (cur.substr(cur.size() - len) == target2025.substr(0, len)) return len;
        }
        return 0;
    };

    char allowed[] = {'0', '2', '5', '6'};
    for (int i = 0; i < n; ++i) {
        for (int state = 0; state < 4; ++state) {
            if (dp[i][state] > n) continue;

            for (char c : allowed) {
                // If adding 'c' completes "2025", this path is forbidden for Condition 2
                if (state == 3 && c == '5') continue;

                int ns = get_next_state(state, c);
                int cost = (s[i] == c ? 0 : 1);
                dp[i + 1][ns] = min(dp[i + 1][ns], dp[i][state] + cost);
            }
        }
    }

    int edits_not_2025 = n + 1;
    for (int state = 0; state < 4; ++state) {
        edits_not_2025 = min(edits_not_2025, dp[n][state]);
    }

    // The answer is the minimum of satisfying either condition
    return min(edits_for_2026, edits_not_2025);
}

int main() {
    // Optimization for fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}