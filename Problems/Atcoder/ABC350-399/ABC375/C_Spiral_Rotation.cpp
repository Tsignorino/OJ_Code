#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<string> vec(n);
    for (auto& s : vec) {
        cin >> s;
    }

    auto ans = vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int l = min({i, n - 1 - i, j, n - 1 - j});
            l = (l + 1) % 4;

            int x = i, y = j;
            while (l--) {
                tie(x, y) = tuple {y, n - 1 - x};
            }
            ans[x][y] = vec[i][j];
        }
    }

    for (auto& s : ans) {
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}