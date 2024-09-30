#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int h, m;
    char c;
    cin >> h >> c >> m;

    int hh = (h + 11) % 12 + 1;
    cout << (hh < 10 ? "0" : "") << hh << ":" << (m < 10 ? "0" : "") << m << " " << (h < 12 ? "AM" : "PM") << '\n';
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