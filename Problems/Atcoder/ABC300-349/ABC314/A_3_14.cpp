#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

const string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

void solve() {
    int n;
    cin >> n;

    cout << s.substr(0, n + 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}