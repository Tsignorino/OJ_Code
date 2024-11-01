#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> S;
auto init = []() {
    for (int i = 2; i <= 500; ++i) {
        S.emplace_back(i * i);
    }
    return 0;
}();

void solve() {
    int n;
    cin >> n;

    map<int, ll> mp;
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (v == 0) {
            cnt++;
        } else {
            for (int i = 0; i < S.size(); ++i) {
                while (v % S[i] == 0) {
                    v /= S[i];
                }
                if (v < S[i]) {
                    break;
                }
            }
        }
        mp[v]++;
    }

    for (auto& [_, c] : mp) {
        ans += c * (c - 1) / 2;
    }

    cout << ans + cnt * (n - cnt) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}