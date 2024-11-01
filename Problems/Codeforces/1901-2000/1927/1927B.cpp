#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    cin >> n;
    int a[n];
    int cnt[26] {};
    string s(n, ' ');
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        for (int j = 0; j < 26; ++j) {
            if (cnt[j] == a[i]) {
                cnt[j]++;
                s[i] = j + 'a';
                break;
            }
        }
    }

    cout << s << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
