#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int l = -1, r = -1, sum = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        char ch;
        cin >> v >> ch;

        if (ch == 'L') {
            sum += (l == -1 ? 0 : abs(v - l));
            l = v;
        } else {
            sum += (r == -1 ? 0 : abs(v - r));
            r = v;
        }
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}