#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    理解 nxt 数组含义
*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> nxt(n + 1);
    nxt[0] = -1;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j != -1 && s[i - 1] != s[j]) {
            j = nxt[j];
        }
        nxt[i] = ++j;
    }

    cout << n - nxt[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
