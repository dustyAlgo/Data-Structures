#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    long long max_score = 0;
    long long swords_needed = 0;

    for (int i = 0; i < n; ++i) {
        swords_needed += b[i];

        if (swords_needed > n) {
            break;
        }

        long long current_difficulty = a[swords_needed - 1];
        
        long long current_score = current_difficulty * (i + 1);
        
        max_score = max(max_score, current_score);
    }

    cout << max_score << "\n";
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