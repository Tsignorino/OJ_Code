#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> vec(n);
    int mx = 0;
    for (string& s : vec) {
        cin >> s;
        mx = max(mx, (int) s.size());
    }

    vector<string> ch(mx, string(n, ' '));
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        int len = vec[i].size();
        for (int j = 0; j < len; ++j) {
            ch[j][n - i - 1] = vec[i][j];
        }
        if (pre > len) {
            for (int k = len; k < pre; ++k) {
                ch[k][n - 1 - i] = '*';
            }
        } else {
            pre = len;
        }
    }

    for (string& vec : ch) {
        for (char& v : vec) {
            cout << v;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}