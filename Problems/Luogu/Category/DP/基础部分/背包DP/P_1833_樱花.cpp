#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Node {
    int t, v, c;
};

void solve() {
    int hs, ms, he, se;
    char ch;
    cin >> hs >> ch >> ms >> he >> ch >> se;

    int T = (he * 60 + se) - (hs * 60 + ms);

    int n;
    cin >> n;

    vector<Node> vec(n);
    for (auto& [t, v, c] : vec) {
        cin >> t >> v >> c;
    }

    /*
        混合背包：完全背包 + 多重背包
    */

    vector<int> f(T + 1);
    for (int i = 0; i < n; ++i) {
        if (vec[i].c == 0) {
            for (int j = vec[i].t; j <= T; ++j) {
                f[j] = max(f[j], f[j - vec[i].t] + vec[i].v);
            }
        } else {
            for (int k = 1; k <= vec[i].c; ++k) {
                for (int j = T; j >= k * vec[i].t; --j) {
                    f[j] = max(f[j], f[j - vec[i].t] + vec[i].v);
                }
            }
        }
    }
    cout << f[T] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}