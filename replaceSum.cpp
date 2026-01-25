#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> combined(n);
    for (int i = 0; i < n; ++i) {
        combined[i] = max(a[i], b[i]);
    }

    vector<int> suffix_max(n);
    suffix_max[n - 1] = combined[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_max[i] = max(combined[i], suffix_max[i + 1]);
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + suffix_max[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        long long ans = pref[r] - pref[l - 1];
        cout << ans << (i == q - 1 ? "" : " ");
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