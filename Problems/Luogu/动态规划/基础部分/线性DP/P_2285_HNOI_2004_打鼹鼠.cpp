#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Node {
    int t, x, y;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Node> vec(m);
    for (auto& [t, x, y] : vec) {
        cin >> t >> x >> y;
    }

    vector<int> f(m, 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(vec[i].x - vec[j].x) + abs(vec[i].y - vec[j].y) <= vec[i].t - vec[j].t) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    cout << ranges::max(f) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}