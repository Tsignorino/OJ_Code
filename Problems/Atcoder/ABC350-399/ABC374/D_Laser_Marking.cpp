#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Node {
    int a, b, c, d;
};

void solve() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<Node> res(n);
    double tot = 0;
    for (auto& [a, b, c, d] : res) {
        cin >> a >> b >> c >> d;
        tot += hypot(a - c, b - d) / t;
    }

    double ans = 2e9;
    for (int k = 0; k < (1 << n); ++k) {
        vector<int> vec(n);
        iota(vec.begin(), vec.end(), 0);

        do {
            double sum = 0;
            int x = 0, y = 0;
            for (int& v : vec) {
                if (k >> v & 1) {
                    sum += hypot(res[v].a - x, res[v].b - y) / s;
                    x = res[v].c, y = res[v].d;
                } else {
                    sum += hypot(res[v].c - x, res[v].d - y) / s;
                    x = res[v].a, y = res[v].b;
                }
            }
            ans = min(ans, sum);
        } while (ranges::next_permutation(vec).found);
    }

    cout << fixed << setprecision(20) << ans + tot << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}