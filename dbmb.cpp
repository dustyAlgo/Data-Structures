#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
void solve() {
    int n, s, x;
    if (!(cin >> n >> s >> x)) return;

    long long current_sum = 0;
    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        current_sum += a_i;
    }

    long long diff = s - current_sum;

    if (diff >= 0 && diff % x == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}