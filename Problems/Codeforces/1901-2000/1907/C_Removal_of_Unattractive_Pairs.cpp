#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> res(26);
    for (int i = 0; i < n; ++i) {
        res[s[i] - 'a']++;
    }

    cout << max(ranges::max(res) * 2 - n, n % 2) << "\n";
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