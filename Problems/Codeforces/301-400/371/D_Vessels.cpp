#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> res(n);

    vector<int> pa(n + 1); // !
    iota(pa.begin(), pa.end(), 0);
    function<int(int)> find = [&](int x) -> int {
        return pa[x] == x ? x : pa[x] = find(pa[x]); // !
    };

    int cnt;
    cin >> cnt;
    while (cnt--) {
        int q, id;
        cin >> q >> id;
        id--;

        if (q == 2) {
            cout << res[id] << "\n";
            continue;
        }

        int val;
        cin >> val;
        for (id = find(id); id < n; id = find(id)) { // !
            if (res[id] + val < vec[id]) {
                res[id] += val;
                break;
            }
            val -= vec[id] - res[id];
            res[id] = vec[id];
            pa[id] = id + 1; // !
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
