#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    种类并查集
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pa(3 * n);
    iota(pa.begin(), pa.end(), 0);

    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };

    int ans = 0;
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (x > n || y > n) {
            ans++;
            continue;
        }

        if (op == 1) {
            if (find(x + n) == find(y) || find(x) == find(y + n)) {
                ans++;
            } else {
                pa[find(x)] = find(y);
                pa[find(x + n)] = find(y + n);
                pa[find(x + n + n)] = find(y + n + n);
            }
        } else {
            if (find(x) == find(y) || find(x) == find(y + n)) {
                ans++;
            } else {
                pa[find(x + n)] = find(y);
                pa[find(x + n + n)] = find(y + n);
                pa[find(x)] = find(y + n + n);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
