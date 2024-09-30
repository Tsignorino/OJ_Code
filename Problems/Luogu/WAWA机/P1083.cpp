#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct node {
    int cnt, s, t;
};

/*
    （多次区间操作）==> 差分
    前缀和、二分答案
*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    vector<node> q(m);
    for (node& n : q) {
        cin >> n.cnt >> n.s >> n.t;
        n.s--, n.t--;
    }

    auto f = [&](int x) {
        vector<ll> diff(n);
        for (int i = 0; i < x; ++i) {
            diff[q[i].s] += q[i].cnt;
            diff[q[i].t + 1] -= q[i].cnt;
        }

        vector<ll> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + diff[i];
            if (pre[i + 1] > vec[i]) {
                return false;
            }
        }
        return true;
    };

    if (f(m)) {
        cout << 0 << "\n";
        return;
    }

    int l = 0, r = m + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        (f(mid) ? l : r) = mid;
    }
    cout << "-1\n" << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
