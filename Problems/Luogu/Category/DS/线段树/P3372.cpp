#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

static constexpr ll inf = 9e18;
struct Tag {
    ll add;
    Tag(ll add = 0) : add(add) {}
    void apply(const Tag& t) { add += t.add; }
};

struct Info { // min, max, sum
    ll mn, mx, sum, len;
    Info(ll _mn = inf, ll _mx = -inf, ll _sum = 0, ll _len = 1) : mn(_mn), mx(_mx), sum(_sum), len(_len) {}
    void apply(const Tag& t) { mn += t.add, mx += t.add, sum += len * t.add; }
};
Info operator+(const Info& a, const Info& b) {
    return Info(min(a.mn, b.mn), max(a.mx, b.mx), a.sum + b.sum, a.len + b.len);
}

class SegTree {
#define ls(o) o << 1
#define rs(o) o << 1 | 1
private:
    ll n;
    vector<Tag> tag;
    vector<Info> info;

    void apply(ll o, const Tag& t) { tag[o].apply(t), info[o].apply(t); }
    void push_up(ll o) { info[o] = info[ls(o)] + info[rs(o)]; }
    void push_down(ll o) {
        apply(ls(o), tag[o]);
        apply(rs(o), tag[o]);
        tag[o] = Tag();
    }

public:
    // SegTree() {}
    SegTree(ll n) : n(n), tag(4 * n), info(4 * n) {}
    SegTree(const vector<Info>& init) : SegTree(init.size()) {
        function<void(ll, ll, ll)> build = [&](ll o, ll l, ll r) -> void {
            if (l == r) {
                info[o] = init[l];
                return;
            }

            ll mid = l + (r - l) / 2;
            build(ls(o), l, mid);
            build(rs(o), mid + 1, r);
            push_up(o);
        };
        build(1, 1, n);
    }

    void update(ll todoL, ll todoR, ll o, ll l, ll r, const Tag& t) {
        if (r < todoL || todoR < l) {
            return;
        }
        if (todoL <= l && r <= todoR) {
            apply(o, t);
            return;
        }

        int mid = l + (r - l) / 2;
        push_down(o);
        update(todoL, todoR, ls(o), l, mid, t);
        update(todoL, todoR, rs(o), mid + 1, r, t);
        push_up(o);
    }
    void update(ll l, ll r, const Tag& t) { update(l, r, 1, 1, n, t); }

    Info query(ll todoL, ll todoR, ll o, ll l, ll r) {
        if (r < todoL || todoR < l) {
            return Info();
        }
        if (todoL <= l && r <= todoR) {
            return info[o];
        }

        ll mid = l + (r - l) / 2;
        push_down(o);
        return query(todoL, todoR, ls(o), l, mid) + query(todoL, todoR, rs(o), mid + 1, r);
    }
    Info query(ll l, ll r) { return query(l, r, 1, 1, n); }
#undef ls
#undef rs
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Info> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i].sum;
    }

    SegTree t(vec);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            t.update(x, y, k);
        } else {
            int x, y;
            cin >> x >> y;
            cout << t.query(x, y).sum << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
