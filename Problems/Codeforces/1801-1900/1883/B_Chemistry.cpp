#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(26);
    string s;
    cin >> s;
    for (char ch : s) {
        vec[ch - 'a']++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        cnt += vec[i] & 1;
    }

    cout << (cnt <= k + 1 ? "YES" : "NO") << "\n";
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
