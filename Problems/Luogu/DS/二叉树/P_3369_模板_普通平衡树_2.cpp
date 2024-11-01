#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static int cnt = 0, root = 0;
static int x = 0, y = 0, z = 0;
std::mt19937 rnd(233);

class Treap {
    struct Node {
        int left, right;
        int val, key;
        int size;
    };

    vector<Node> tree;

public:
    Treap() = default;
    Treap(int size) : tree(size) {}

private:
    int newNode(int val) {
        cnt++;
        tree[cnt].val = val;
        tree[cnt].key = rnd();
        tree[cnt].size = 1;
        return cnt;
    }
    void update(int cur) { tree[cur].size = tree[tree[cur].left].size + tree[tree[cur].right].size + 1; }

    // 按小于等于某个值分裂
    void split(int cur, int val, int& x, int& y) {
        if (!cur) {
            x = y = 0;
        } else {
            if (tree[cur].val <= val) {
                x = cur;
                split(tree[cur].right, val, tree[cur].right, y);
            } else {
                y = cur;
                split(tree[cur].left, val, x, tree[cur].left);
            }
            update(cur);
        }
    }

    // x 树中的值不大于 y 树中的值
    int merge(int x, int y) {
        if (!x || !y) {
            return x + y;
        }
        if (tree[x].key > tree[y].key) { // < <= > >=
            tree[x].right = merge(tree[x].right, y);
            update(x);
            return x;
        } else {
            tree[y].left = merge(x, tree[y].left);
            update(y);
            return y;
        }
    }

public:
    void insert(int val) {
        split(root, val, x, y);
        root = merge(merge(x, newNode(val)), y);
    }
    void del(int val) {
        split(root, val, x, z);
        split(x, val - 1, x, y);
        y = merge(tree[y].left, tree[y].right);
        root = merge(merge(x, y), z);
    }
    int getRank(int val) {
        split(root, val - 1, x, y);
        int ans = tree[x].size + 1;
        root = merge(x, y);
        return ans;
    }
    int getNum(int rank) {
        int cur = root;
        while (cur) {
            if (tree[tree[cur].left].size + 1 == rank) {
                break;
            } else if (tree[tree[cur].left].size >= rank) {
                cur = tree[cur].left;
            } else {
                rank -= tree[tree[cur].left].size + 1;
                cur = tree[cur].right;
            }
        }
        return tree[cur].val;
    }
    int getPre(int val) {
        split(root, val - 1, x, y);
        int cur = x;
        while (tree[cur].right) {
            cur = tree[cur].right;
        }
        int ans = tree[cur].val;
        root = merge(x, y);
        return ans;
    }
    int getNxt(int val) {
        split(root, val, x, y);
        int cur = y;
        while (tree[cur].left) {
            cur = tree[cur].left;
        }
        int ans = tree[cur].val;
        root = merge(x, y);
        return ans;
    }
};

void solve() {
    int q;
    cin >> q;

    const int MX = 1e5 + 5;
    Treap f(MX);

    while (q--) {
        int Op, x;
        cin >> Op >> x;

        switch (Op) {
            case 1: f.insert(x); break;
            case 2: f.del(x); break;
            case 3: cout << f.getRank(x) << "\n"; break;
            case 4: cout << f.getNum(x) << "\n"; break;
            case 5: cout << f.getPre(x) << "\n"; break;
            case 6: cout << f.getNxt(x) << "\n"; break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}