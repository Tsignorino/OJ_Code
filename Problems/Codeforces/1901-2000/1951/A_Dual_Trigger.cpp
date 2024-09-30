#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = count(s.begin(), s.end(), '1');
    if (cnt == 2) {
        cout << (s.find('1') == s.rfind('1') - 1 ? "NO" : "YES") << "\n";
    } else {
        cout << (cnt & 1 ? "NO" : "YES") << "\n";
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