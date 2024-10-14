#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<vector<int>> lines = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

void solve() {
    vector<int> g(9);
    for (int i = 0; i < 9; ++i) {
        cin >> g[i];
    }

    vector<int> res(9);
    iota(res.begin(), res.end(), 0);

    int x = 0, y = 0;
    do {
        int ok = 1;
        for (auto li : lines) {
            vector<int> f;
            for (int& v : res) {
                if (ranges::count(li, v)) {
                    f.push_back(g[v]);
                }
            }
            if (f[0] == f[1]) {
                ok = 0;
            }
        }
        x += ok;
        y += 1;
    } while (ranges::next_permutation(res).found);

    cout << fixed << setprecision(30) << double(x) / y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}