#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int dot = 0, seg = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            dot++;
            if (i == 0 || s[i - 1] != '.') {
                seg++;
            }
        }
    }

    s = '0' + s + '0';

    while (m--) {
        int p;
        char ch;
        cin >> p >> ch;
        if ((s[p] == '.') != (ch == '.')) {
            int d = -1;
            if (ch == '.') {
                d = 1;
            }
            dot += d;

            if (s[p - 1] != '.' && s[p + 1] != '.') {
                seg += d;
            } else if (s[p - 1] == '.' && s[p + 1] == '.') {
                seg -= d;
            }
            s[p] = ch;
        }
        cout << dot - seg << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
