#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    cout << (s.find('R') < s.find('M') ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
