#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    注意数据范围

    ! 要将 vec 放在 while 循环外面
*/
void solve() {
    ll a, b, c;

    vector memo(21, vector(21, vector<ll>(21, -1)));
    function<ll(ll, ll, ll)> dfs = [&](ll a, ll b, ll c) -> ll {
        if (a <= 0 || b <= 0 || c <= 0) {
            return 1;
        }

        if (a > 20 || b > 20 || c > 20) {
            ll& res = memo[20][20][20];
            if (res != -1) {
                return res;
            }
            return res = dfs(20, 20, 20);
        }

        ll& res = memo[a][b][c];
        if (res != -1) {
            return res;
        }

        if (a < b && b < c) {
            memo[a][b][c - 1] = dfs(a, b, c - 1);
            memo[a][b - 1][c - 1] = dfs(a, b - 1, c - 1);
            memo[a][b - 1][c] = dfs(a, b - 1, c);
            return res = memo[a][b][c - 1] + memo[a][b - 1][c - 1] - memo[a][b - 1][c];
        }

        memo[a - 1][b][c] = dfs(a - 1, b, c);
        memo[a - 1][b - 1][c] = dfs(a - 1, b - 1, c);
        memo[a - 1][b][c - 1] = dfs(a - 1, b, c - 1);
        memo[a - 1][b - 1][c - 1] = dfs(a - 1, b - 1, c - 1);
        return res = memo[a - 1][b][c] + memo[a - 1][b - 1][c] + memo[a - 1][b][c - 1] - memo[a - 1][b - 1][c - 1];
    };

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << format("w({}, {}, {}) = {}\n", a, b, c, dfs(a, b, c));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}