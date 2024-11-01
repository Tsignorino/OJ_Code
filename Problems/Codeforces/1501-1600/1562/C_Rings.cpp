#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            flag = true;
            if (i >= n / 2) {
                cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
                break;
            } else {
                cout << i + 2 << " " << n << " " << i + 1 << " " << n << "\n";
                break;
            }
        }
    }

    if (flag == false) {
        cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
    }
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
