#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    好的三元组在数位加法中不进位，所以只需要考虑每一位 b 的情况

    个数 = sum(1...(b+1))
*/

void solve() {
    int n;
    cin >> n;

    ll ans = 1;
    while (n) {
        int b = n % 10;
        ans *= (b + 1) * (b + 2) / 2;
        n /= 10;
    }
    cout << ans << "\n";
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