#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;
    n--;

    string s;
    if (n == 0) {
        s.push_back('0');
    }
    while (n) {
        s.push_back(n % 5 * 2 + '0');
        n /= 5;
    }
    cout << string(s.rbegin(), s.rend()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}