#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> nxt(n + 1);
    nxt[0] = -1;
    int i = 2, j = 0;
    while (i <= n) {
        if (s[i - 1] == s[j]) {
            nxt[i++] = ++j;
        } else if (j > 0) {
            j = nxt[j];
        } else {
            nxt[i++] = 0;
        }
    }

    // 最长匹配长度，最短匹配长度
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        int j = i;

        // 递归并简化
        while (nxt[j]) {
            j = nxt[j];
        }
        if (nxt[i]) {
            nxt[i] = j;
        }

        ans += i - j;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
