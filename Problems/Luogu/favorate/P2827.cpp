#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    注意单调性
*/

void solve() {
    int n, m, l, u, v, t;
    cin >> n >> m >> l >> u >> v >> t;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec, greater<>());

    vector<queue<int>> q(3);
    for (int& v : vec) {
        q[0].emplace(v);
    }

    for (int i = 0; i < m; ++i) {
        pair<int, int> p = max(
            {pair(q[0].empty() ? INT_MIN / 2 : q[0].front(), 0), pair(q[1].empty() ? INT_MIN / 2 : q[1].front(), 1),
             pair(q[2].empty() ? INT_MIN / 2 : q[2].front(), 2)}
        );

        int x = p.first + l * i, j = p.second;
        q[j].pop();

        int b = x * 1ll * u / v, c = x - b;
        q[1].emplace(b - l - l * i);
        q[2].emplace(c - l - l * i);

        if ((i + 1) % t == 0) {
            cout << x << " ";
        }
    }

    cout << "\n";

    for (int i = 1; i <= n + m; ++i) {
        pair<int, int> p = max(
            {pair(q[0].empty() ? INT_MIN / 2 : q[0].front(), 0), pair(q[1].empty() ? INT_MIN / 2 : q[1].front(), 1),
             pair(q[2].empty() ? INT_MIN / 2 : q[2].front(), 2)}
        );

        int x = p.first, j = p.second;
        q[j].pop();
        if (i % t == 0) {
            cout << x + l * m << " ";
        }
    }
}

//! TLE
void fake_solve() {
    ll n, m, l, u, v, t;
    cin >> n >> m >> l >> u >> v >> t;

    struct node {
        ll x, t0; // x：长度    t0：上次被切的时间
        node(ll x, ll t0) : x(x), t0(t0) {}
    };

    auto comp = [&](const node& p1, const node& p2) {
        return p1.x + (m - p1.t0) * l < p2.x + (m - p2.t0) * l;
    };

    priority_queue<node, vector<node>, decltype(comp)> q(comp);
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        q.emplace(val, 1);
    }

    for (int i = 1; i <= m; ++i) {
        ll x = q.top().x, t0 = q.top().t0;
        q.pop();
        x += (i - t0) * l;
        if (i % t == 0) {
            cout << x << " ";
        }
        q.emplace(u * x / v, i + 1);
        q.emplace(x - u * x / v, i + 1);
    }
    cout << "\n";

    for (int i = 1; i <= n + m; ++i) {
        if (i % t == 0) {
            ll x = q.top().x, t0 = q.top().t0;
            cout << x + (m + 1 - t0) * l << " ";
        }
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
