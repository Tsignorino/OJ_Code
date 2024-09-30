#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;

    vector vec(2, vector<int>(n + 2));
    int cnt = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;

        vec[x][y] ^= 1;
        int s = vec[x ^ 1][y - 1] + vec[x ^ 1][y] + vec[x ^ 1][y + 1];
        if (vec[x][y] > 0) {
            cnt += s;
        } else {
            cnt -= s;
        }

        if (cnt > 0 || vec[0][1] > 0 || vec[1][n] > 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}