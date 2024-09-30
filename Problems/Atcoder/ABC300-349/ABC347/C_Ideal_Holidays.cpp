#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> days;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;

        d %= a + b;
        days.emplace_back(d);
        days.emplace_back(d + a + b);
    }

    ranges::sort(days);

    for (int i = 0; i < n; ++i) {
        if (days[i + n - 1] - days[i] <= a - 1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}