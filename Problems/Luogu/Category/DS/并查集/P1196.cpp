#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> pa(30001), dis(30001), size(30001, 1);
    iota(pa.begin(), pa.end(), 0);

    function<int(int)> find = [&](int x) {
        if (x == pa[x]) {
            return x;
        }
        int k = pa[x];
        pa[x] = find(pa[x]);
        dis[x] += dis[k];
        size[x] = size[pa[x]];
        return pa[x];
    };

    while (n--) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;

        int rx = find(x), ry = find(y);
        if (ch == 'M') {
            pa[rx] = ry;
            dis[rx] += size[ry];
            size[rx] += size[ry];
            size[ry] = size[rx];
        } else {
            if (rx == ry) {
                cout << abs(dis[x] - dis[y]) - 1 << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
