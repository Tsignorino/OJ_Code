#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    if (k == 1) {
        cout << (n - 1) * a << "\n";
        return;
    }

    ll cost = 0;
    while (n != 1) {
        if (n < k) {
            cout << cost + (n - 1) * a;
            return;
        }

        if (n > k && n % k != 0) {
            cost += (n - n / k * k) * a;
            n = n / k * k;
        }

        if (n % k == 0) {
            cost += min((n - n / k) * a, b);
            n /= k;
        }
    }
    cout << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
