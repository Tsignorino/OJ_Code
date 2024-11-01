#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }

    for (int i = 0; i < n; ++i) {
        int res = -1;
        int id = -1;

        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            int dx = vec[j].first - vec[i].first, dy = vec[j].second - vec[i].second;
            int dis = dx * dx + dy * dy;
            if (res < dis) {
                res = dis;
                id = j;
            }
        }

        cout << id + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
