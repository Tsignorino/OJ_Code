#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

constexpr int N = 1e5;
vector<int> bin;
vector<int> dp(N);
auto init = [] {
    for (int s = 1; s < (1 << 5); ++s) {
        int v = 0;
        for (int i = 4; i >= 0; --i) {
            v = v * 10 + (s >> i & 1);
        }
        bin.emplace_back(v);
    }
    bin.emplace_back(N);

    dp[1] = 1;
    for (int& v : bin) {
        for (int i = 1; i * v <= N; ++i) {
            dp[i * v] |= dp[i];
        }
    }

    return 0;
}();

void solve() {
    int n;
    cin >> n;

    cout << (dp[n] ? "YES" : "NO") << "\n";
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