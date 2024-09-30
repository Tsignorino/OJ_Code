#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int h, m, a;
    char ch;
    cin >> h >> ch >> m >> a;

    m += a;
    h += m / 60;
    h %= 24;
    m %= 60;

    cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}