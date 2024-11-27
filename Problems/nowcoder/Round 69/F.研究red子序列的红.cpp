// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <class Info>
class SegTree {
    const int n;
    vector<Info> tree;
    string s;

    void pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

public:
    SegTree(int n) : n(n), tree(4 << __lg(n)) {}
    SegTree(const string& s) : SegTree(s.size()) {
        this->s = s;

        auto build = [&](auto&& self, int o, int l, int r) -> void {
            if (l == r) {
                if (s[l] == 'r') {
                    tree[o].r = 1;
                } else if (s[l] == 'e') {
                    tree[o].e = 1;
                } else if (s[l] == 'd') {
                    tree[o].d = 1;
                }
                return;
            }
            int m = l + (r - l) / 2;
            self(self, o << 1, l, m);
            self(self, o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(build, 1, 0, n - 1);
    }

    char get(int id) { return s[id]; }

    void modify(int id, char v, int o, int l, int r) {
        if (l == r) {
            if (s[id] == 'r') {
                tree[o].r--;
            } else if (s[id] == 'e') {
                tree[o].e--;
            } else if (s[id] == 'd') {
                tree[o].d--;
            }
            s[id] = v;
            if (s[id] == 'r') {
                tree[o].r++;
            } else if (s[id] == 'e') {
                tree[o].e++;
            } else if (s[id] == 'd') {
                tree[o].d++;
            }
            return;
        }
        int m = l + (r - l) / 2;
        if (id <= m) {
            modify(id, v, o << 1, l, m);
        } else {
            modify(id, v, o << 1 | 1, m + 1, r);
        }
        pull(o);
    }
    void modify(int id, char v) { modify(id, v, 1, 0, n - 1); }

    Info queryAll() { return tree[1]; }
};
struct Info {
    ll r = 0, e = 0, d = 0, re = 0, ed = 0, red = 0;
};
Info operator+(const Info& p, const Info& q) {
    return Info(p.r + q.r, p.e + q.e, p.d + q.d, p.re + q.re + p.r * q.e, p.ed + q.ed + p.e * q.d, p.red + q.red + p.re * q.d + p.r * q.ed);
}

void solve() {
    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;

    SegTree<Info> ts(s), tt(t);

    while (q--) {
        int id;
        cin >> id;
        id--;

        char t1 = ts.get(id), t2 = tt.get(id);
        ts.modify(id, t2);
        tt.modify(id, t1);
        cout << ts.queryAll().red - tt.queryAll().red << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}