#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    操作一 只在字符串长度为奇数时执行一次
*/

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector C(2, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        C[i % 2][s[i] - 'a']++;
    }

    int ans = n;
    if (n % 2 == 0) {
        ans = n - ranges::max(C[0]) - ranges::max(C[1]);
    } else {
        for (int i = n - 1; i >= 0; --i) {
            C[i % 2][s[i] - 'a']--;
            if (n % 2 == 1) {
                ans = min(ans, n - ranges::max(C[0]) - ranges::max(C[1]));
            }
            C[(i + 1) % 2][s[i] - 'a']++;
        }
    }
    cout << ans << "\n";
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