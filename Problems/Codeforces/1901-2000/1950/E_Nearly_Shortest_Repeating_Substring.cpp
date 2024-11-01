#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int k = 1; k <= n; k++) {
        if (n % k) {
            continue;
        }

        //* 最多有几个字符相同
        // int total = 0;
        // for (int i = 0; i < k; i++) {
        //     vector<int> cnt(26);
        //     int maxV = 0;
        //     for (int j = i; j < n; j += k) {
        //         maxV = max(maxV, ++cnt[s[j] - 'a']);
        //     }
        //     total += maxV;
        // }

        // if (total >= n - 1) {
        //     cout << k << '\n';
        //     break;
        // }

        for (int i = 0; i < n && i <= k; i += k) {
            int ans = 0;
            for (int j = 0; j < n; j++) {
                ans += (s[i + j % k] != s[j]);
            }

            if (ans <= 1) {
                cout << k << "\n";
                return;
            }
        }
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