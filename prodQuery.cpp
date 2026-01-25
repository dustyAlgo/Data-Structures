#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<bool> has(n + 1, false);
    vector<int> distinct_nums;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (!has[x]) {
            has[x] = true;
            if (x > 1) {
                distinct_nums.push_back(x);
            }
        }
    }
    
    sort(distinct_nums.begin(), distinct_nums.end());

    vector<int> dp(n + 1, INF);

    for (int i = 1; i <= n; ++i) {
        if (has[i]) {
            dp[i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == INF) continue;

        for (int v : distinct_nums) {
            long long next_val = (long long)i * v;
            
            if (next_val > n) break; 

            if (dp[i] + 1 < dp[next_val]) {
                dp[next_val] = dp[i] + 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == INF) cout << "-1";
        else cout << dp[i];
        
        cout << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}