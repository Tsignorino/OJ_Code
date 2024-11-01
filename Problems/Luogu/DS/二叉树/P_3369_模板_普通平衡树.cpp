#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

namespace mySplay {
    struct Node {
        int s[2] {};
        int pa;
        int val;
        int cnt;
        int size;

        Node() = default;
        Node(int p, int v) : pa(p), val(v) { cnt = size = 1; }
    };

    vector<Node> f;
    int root = 0, idx = 0;

    void pull(int x) {
        f[x].size = f[f[x].s[0]].size + f[f[x].s[1]].size + f[x].cnt;
    }

    void rotate(int x) {
        int y = f[x].pa, z = f[y].pa;
        int k = f[y].s[1] == x;
        // 冲突的子节点
        f[y].s[k] = f[x].s[k ^ 1];
        f[f[x].s[k ^ 1]].pa = y;
        // 调换父子关系
        f[x].s[k ^ 1] = y;
        f[y].pa = x;
        f[z].s[f[z].s[1] == y] = x;
        f[x].pa = z;
        pull(y);
        pull(x);
    }

    // k > 0，把 x 转到 k 下面
    // k = 0，把 x 转到根
    void splay(int x, int k) {
        while (f[x].pa != k) {
            int y = f[x].pa, z = f[y].pa;
            if (z != k) {
                (f[y].s[0] == x) ^ (f[z].s[0] == y) ? rotate(x) : rotate(y);
            }
            rotate(x);
        }
        if (k == 0) {
            root = x;
        }
    }

    // 找到节点并旋转至根
    void find(int v) {
        int x = root;
        while (f[x].s[v > f[x].val] && v != f[x].val) {
            x = f[x].s[v > f[x].val];
        }
        splay(x, 0);
    }

    int getPre(int v) {
        find(v);
        int x = root;
        if (f[x].val < v) {
            return x;
        }
        x = f[x].s[0];
        while (f[x].s[1]) {
            x = f[x].s[1];
        }
        splay(x, 0);
        return x;
    }
    int getNxt(int v) {
        find(v);
        int x = root;
        if (f[x].val > v) {
            return x;
        }
        x = f[x].s[1];
        while (f[x].s[0]) {
            x = f[x].s[0];
        }
        splay(x, 0);
        return x;
    }

    void del(int v) {
        int pre = getPre(v);
        int nxt = getNxt(v);
        splay(pre, 0);
        splay(nxt, pre);
        int d = f[nxt].s[0];
        if (f[d].cnt > 1) {
            f[d].cnt--;
            splay(d, 0);
        } else {
            f[nxt].s[0] = 0;
            splay(nxt, 0);
        }
    }

    void insert(int v) {
        int x = root, p = 0;
        while (x && f[x].val != v) {
            p = x;
            x = f[x].s[v > f[x].val];
        }
        if (x) {
            f[x].cnt++;
        } else {
            x = ++idx;
            f[p].s[v > f[p].val] = x;
            f[x] = Node(p, v);
        }
        splay(x, 0);
    }

    int getRank(int v) {
        // find(v);
        // return f[f[root].s[0]].size;
        insert(v);
        int res = f[f[root].s[0]].size;
        del(v);
        return res;
    }
    int getNum(int k) {
        int x = root;
        while (true) {
            int y = f[x].s[0];
            if (f[y].size + f[x].cnt < k) {
                k -= f[y].size + f[x].cnt;
                x = f[x].s[1];
            } else if (f[y].size >= k) {
                x = y;
            } else {
                break;
            }
        }
        splay(x, 0);
        return f[x].val;
    }

    auto init = []() {
        const int N = 1e6 + 1e5;
        f.resize(N);

        // 哨兵
        insert(-2e9);
        insert(2e9);

        return 0;
    }();
}; // namespace mySplay
using namespace mySplay;

void solve() {
    int q;
    cin >> q;

    while (q--) {
        int Op, x;
        cin >> Op >> x;

        switch (Op) {
            case 1: insert(x); break;
            case 2: del(x); break;
            case 3: cout << getRank(x) << "\n"; break;
            case 4: cout << getNum(x + 1) << "\n"; break;
            case 5: cout << f[getPre(x)].val << "\n"; break;
            case 6: cout << f[getNxt(x)].val << "\n"; break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}