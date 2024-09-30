#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct Rectangle {
    ll x1, y1, x2, y2;
};

struct Line {
    ll x, down, up, flag; // 横坐标，下界，上界，标志
};

struct Node {
    ll len, cover = 0, cnt = 0;
};

/*
    扫描线 + 线段树（题目有点狠，数据和空间难以捉摸）
*/
void solve() {
    ll n;
    cin >> n;
    vector<Rectangle> rec(n);
    vector<Line> lines;
    vector<ll> y;
    for (auto& [x1, y1, x2, y2] : rec) {
        cin >> x1 >> y1 >> x2 >> y2;
        lines.emplace_back(x1, y1, y2, 1), lines.emplace_back(x2, y1, y2, -1);
        y.emplace_back(y1), y.emplace_back(y2);
    }

    ranges::sort(lines, [&](const Line& l1, const Line& l2) { return l1.x < l2.x; });

    ranges::sort(y);
    y.erase(unique(y.begin(), y.end()), y.end());

    vector<Node> tree(n << 5);
    function<void(ll, ll, ll)> build = [&](ll o, ll l, ll r) -> void {
        if (l < r) {
            ll mid = l + (r - l) / 2;
            build(o << 1, l, mid);
            build(o << 1 | 1, mid + 1, r);
        }
        tree[o].len = y[r + 1] - y[l];
    };
    function<void(ll)> push_up = [&](ll o) -> void {
        if (tree[o].cnt) {
            tree[o].cover = tree[o].len;
        } else {
            tree[o].cover = tree[o << 1].cover + tree[o << 1 | 1].cover;
        }
    };
    function<void(ll, ll, ll, ll, ll, ll)> update = [&](ll todol, ll todor, ll v, ll o, ll l, ll r) -> void {
        if (todol <= l && r <= todor) {
            tree[o].cnt += v;
            push_up(o);
            return;
        }
        ll mid = l + (r - l) / 2;
        if (todol <= mid) {
            update(todol, todor, v, o << 1, l, mid);
        }
        if (todor > mid) {
            update(todol, todor, v, o << 1 | 1, mid + 1, r);
        }
        push_up(o);
    };

    unsigned long long ans = 0;
    ll m = n << 1;
    build(1, 0, m - 1);
    for (ll i = 0; i < m; ++i) {
        ll l = ranges::lower_bound(y, lines[i].down) - y.begin();
        ll r = ranges::lower_bound(y, lines[i].up) - y.begin();
        update(l, r - 1, lines[i].flag, 1, 0, m - 1);
        ans += (unsigned long long) tree[1].cover * (lines[i + 1].x - lines[i].x);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
