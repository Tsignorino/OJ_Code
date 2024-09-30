#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;

    string t;
    cin >> t;

    vector<string> vec(h);
    for (auto& s : vec) {
        cin >> s;
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            bool ok = vec[i][j] == '.';
            for (int k = 0, x = i, y = j; k < n && ok; ++k) {
                if (t[k] == 'L') {
                    y--;
                }
                if (t[k] == 'R') {
                    y++;
                }
                if (t[k] == 'U') {
                    x--;
                }
                if (t[k] == 'D') {
                    x++;
                }
                ok &= vec[x][y] == '.';
            }
            ans += ok;
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