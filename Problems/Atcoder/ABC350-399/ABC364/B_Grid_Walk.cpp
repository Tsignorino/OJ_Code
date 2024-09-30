#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<string> vec(n);
    for (string& s : vec) {
        cin >> s;
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'L' && y > 0 && vec[x][y - 1] == '.') {
            y--;
        }
        if (s[i] == 'R' && y < m - 1 && vec[x][y + 1] == '.') {
            y++;
        }
        if (s[i] == 'U' && x > 0 && vec[x - 1][y] == '.') {
            x--;
        }
        if (s[i] == 'D' && x < n - 1 && vec[x + 1][y] == '.') {
            x++;
        }
    }
    cout << x + 1 << " " << y + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}