#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
const long long MOD = 1e9 + 7;

void solve() {
    int n;
    long long Ax, Ay, Bx, By;
    if (!(cin >> n >> Ax >> Ay >> Bx >> By)) return;

    vector<long long> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    vector<long long> y(n);
    for (int i = 0; i < n; ++i) cin >> y[i];

    map<long long, pair<long long, long long>> cols;
    
    for (int i = 0; i < n; ++i) {
        if (cols.find(x[i]) == cols.end()) {
            cols[x[i]] = {y[i], y[i]};
        } else {
            cols[x[i]].first = min(cols[x[i]].first, y[i]);   
            cols[x[i]].second = max(cols[x[i]].second, y[i]);
        }
    }

    long long prev_cost_min = 0;
    long long prev_cost_max = 0;
    long long prev_y_min = Ay;
    long long prev_y_max = Ay;

    for (auto const& [curr_x, range] : cols) {
        long long curr_y_min = range.first;
        long long curr_y_max = range.second;
        long long col_height = abs(curr_y_max - curr_y_min);

        long long from_prev_min_to_curr_min = prev_cost_min + abs(prev_y_min - curr_y_max) + col_height;
        long long from_prev_max_to_curr_min = prev_cost_max + abs(prev_y_max - curr_y_max) + col_height;
        long long next_cost_min = min(from_prev_min_to_curr_min, from_prev_max_to_curr_min);

        long long from_prev_min_to_curr_max = prev_cost_min + abs(prev_y_min - curr_y_min) + col_height;
        long long from_prev_max_to_curr_max = prev_cost_max + abs(prev_y_max - curr_y_min) + col_height;
        long long next_cost_max = min(from_prev_min_to_curr_max, from_prev_max_to_curr_max);

        prev_cost_min = next_cost_min;
        prev_cost_max = next_cost_max;
        prev_y_min = curr_y_min;
        prev_y_max = curr_y_max;
    }

    long long total_y_cost = min(
        prev_cost_min + abs(prev_y_min - By),
        prev_cost_max + abs(prev_y_max - By)
    );
    long long total_x_cost = Bx - Ax;

    long long ans = total_y_cost + total_x_cost;

    cout << ans % MOD << "\n";
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