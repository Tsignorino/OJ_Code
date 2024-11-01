#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector pre(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;

            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + (ch == 'B');
        }
    }

    function<ll(ll, ll)> get = [&](ll a, ll b) -> ll {
        if (a > n) {
            return get(n, b) * (a / n) + get(a % n, b);
        }
        if (b > n) {
            return get(a, n) * (b / n) + get(a, b % n);
        }
        return pre[a][b];
    };

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c++, d++;

        cout << get(a, b) + get(c, d) - get(a, d) - get(c, b) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}