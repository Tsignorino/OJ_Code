#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

// 盖印章

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> nxt(n + 1);
    nxt[0] = -1;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j != -1 && s[i - 1] != s[j]) {
            j = nxt[j];
        }
        nxt[i] = ++j;
    }

    vector<int> f(n + 1);
    map<int, int> map;
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        if (map[f[nxt[i]]] >= i - nxt[i]) {
            f[i] = f[nxt[i]];
        }
        map[f[i]] = i;
    }
    cout << f[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
