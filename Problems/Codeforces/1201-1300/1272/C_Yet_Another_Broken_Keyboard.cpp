#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    bool exist[26] {};
    char c;
    while (k--) {
        cin >> c;
        exist[c - 'a'] = 1;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = i;
        while (k < n && exist[s[k] - 'a'] == 1) { //* 注意数据范围
            k++;
        }
        ans += 1LL * (k - i) * (k - i + 1) / 2;
        i = k;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
