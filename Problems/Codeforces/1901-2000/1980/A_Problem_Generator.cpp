#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> vec(7);
    for (char& ch : s) {
        vec[ch - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 7; ++i) {
        ans += max(m - vec[i], 0);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
