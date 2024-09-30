#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> pos(n);
    for (int& v : pos) {
        cin >> v;
        v--;
    }

    string s;
    cin >> s;

    vector<int> vis(n), f(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }

        int j = i, cnt = 0;
        while (!vis[j]) {
            cnt += s[j] & 1 ^ 1; // s[j] == '0'
            vis[j] = 1;
            j = pos[j];
        }

        do {
            f[j] = cnt;
            j = pos[j];
        } while (j != i);
    }

    for (int& v : f) {
        cout << v << " ";
    }
    cout << "\n";
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