#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    n   需要发送消息的时刻的数量
    f   手机初始电量
    a   单位时间电量消耗
    b   关闭、打开的消耗
*/
void solve() {
    int n, f, a, b;
    cin >> n >> f >> a >> b;

    long long cost = 0;
    int cur, pre = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        cost += min((cur - pre) * 1LL * a, b * 1LL);
        pre = cur;
    }

    cout << (cost < f ? "YES" : "NO") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
