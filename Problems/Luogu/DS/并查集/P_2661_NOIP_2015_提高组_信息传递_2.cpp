#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int mn = INT_MAX; // 记录最小环长度

    vector<int> pa(n + 1);
    iota(pa.begin(), pa.end(), 0);

    function<int(int, int&)> find = [&](int x, int& cnt) { // 栈区开不下
        cnt++;
        return pa[x] == x ? x : find(pa[x], cnt);
    };

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;

        int cnt = 0;
        if (find(p, cnt) == i) {
            mn = min(mn, cnt);
        } else {
            pa[i] = p;
        }
    }

    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}