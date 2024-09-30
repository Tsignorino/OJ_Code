#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    s = 'L' + s + 'L';
    n += 2;

    int flag = 1, p = 0;
    while (p < n - 1) {
        if (s[p] == 'L') {
            int ok = 0;
            for (int i = p + 1; i < n && i <= p + m; ++i) {
                if (s[i] == 'L') {
                    p = i;
                    ok = 1;
                    break;
                }
            }
            if (ok == 0) {
                p += m;
                if (s[p] == 'C') {
                    flag = 0;
                    break;
                }
            }
        } else {
            p += 1;
            if (s[p] == 'C') {
                flag = 0;
                break;
            }
            k--;
        }
    }

    cout << (flag && k >= 0 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}