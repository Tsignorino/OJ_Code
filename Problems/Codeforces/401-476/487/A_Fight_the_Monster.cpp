#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Item {
    int HP, ATK, DEF;
};

void solve() {
    Item y, m;
    cin >> y.HP >> y.ATK >> y.DEF;
    cin >> m.HP >> m.ATK >> m.DEF;

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 1e9;
    for (int i = max(m.DEF + 1, y.ATK); i <= m.HP + m.DEF; ++i) { // 当前的攻击
        int mn = 1e9;
        for (int j = y.DEF; j <= m.ATK; ++j) { // 当前的防御
            int k = (m.HP + i - m.DEF - 1) / (i - m.DEF) * max(0, m.ATK - j);
            mn = min(mn, (j - y.DEF) * c + (k >= y.HP ? k - y.HP + 1 : 0) * a);
        }
        ans = min(ans, (i - y.ATK) * b + (int) (mn == 1e9 ? 0 : mn));
    }
    cout << (ans == 1e9 ? 0 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}