#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

char z[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', //
              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

void solve() {
    int n, m;
    cin >> n >> m;

    string ans;
    int res = n;
    while (res) {
        int v = res % m; // m < 0
        if (v < 0) {
            v -= m;
            res += m;
        }
        res /= m;
        ans.push_back(z[v]);
    }
    ranges::reverse(ans);
    cout << n << "=" << ans << "(base" << m << ")\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}