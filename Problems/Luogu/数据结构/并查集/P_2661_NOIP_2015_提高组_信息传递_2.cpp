#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> pa(n + 1);
    iota(pa.begin(), pa.end(), 0);

    function<int(int, int&)> find = [&](int x, int& cnt) { // 栈区开不下
        cnt++;
        return pa[x] == x ? x : find(pa[x], cnt);
    };

    int ans = INT_MAX; // 记录最小环长度
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;

        int cnt = 0;
        if (find(p, cnt) == i) {
            ans = min(ans, cnt);
        } else {
            pa[i] = p;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}