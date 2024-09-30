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

    // * Solution 1 */
    // int pre = -1;
    // long long ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (exist[s[i] - 'a'] == 1) {
    //         ans += i - pre;
    //     } else {
    //         pre = i;
    //     }
    // }

    // * Solution 2 */
    // int pre = -1, cur = -1, i = 0;
    // long long ans = 0;
    // while (i < n) {
    //     if (exist[s[i] - 'a'] == 0) {
    //         pre = cur;
    //         cur = i;
    //         ans += 1LL * (cur - pre - 1) * (cur - pre) / 2;
    //     }
    //     i++;
    // }
    // ans += 1LL * (i - cur - 1) * (i - cur) / 2;

    // * Solution 3 */
    long long ans = 0;
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
