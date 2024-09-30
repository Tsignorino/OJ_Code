#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct T {
    int x, y, e;
};

void solve() {
    int n;
    cin >> n;
    vector<T> vec(n);
    vector<int> tmp;
    for (auto& [x, y, e] : vec) {
        cin >> x >> y >> e;
        tmp.emplace_back(x);
        tmp.emplace_back(y);
    }

    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (auto& [x, y, e] : vec) {
        x = ranges::lower_bound(tmp, x) - tmp.begin();
        y = ranges::lower_bound(tmp, y) - tmp.begin();
    }

    vector<int> pa(2 * n + 1);
    iota(pa.begin(), pa.end(), 0);
    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };

    for (auto& [x, y, e] : vec) {
        if (e == 1) {
            int rx = find(x), ry = find(y);
            if (rx == ry) {
                continue;
            }
            pa[rx] = ry;
        }
    }
    for (auto& [x, y, e] : vec) {
        if (e == 0) {
            int rx = find(x), ry = find(y);
            if (rx == ry) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}