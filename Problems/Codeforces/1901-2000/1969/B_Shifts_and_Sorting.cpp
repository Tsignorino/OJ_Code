#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    逆序数
*/

void solve() {
    string s;
    cin >> s;

    ll ans = 0;
    int cnt = 0;
    for (char ch : s) {
        if (ch == '1') {
            cnt++;
        } else {
            if (cnt > 0) {
                ans += cnt + 1;
            }
        }
    }

    // int id = ranges::find(s, '1') - s.begin();
    // for (int i = id, pre = id; i < s.size(); ++i) {
    //     if (s[i] == '0') {
    //         ans += i - pre + 1;
    //         pre++;
    //     }
    // }
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