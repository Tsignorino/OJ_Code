#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static int cnt = 0, root = 0;
static int x = 0, y = 0, z = 0;
std::mt19937 rnd(233);

class Seg_Treap {
    struct Node {
        int left, right;
        int val, key;
        int size;
        bool isReverse;
    };

    vector<Node> tree;

public:
    Seg_Treap() = default;
    Seg_Treap(int size) : tree(size) {}

private:
    void update(int cur) { tree[cur].size = tree[tree[cur].left].size + tree[tree[cur].right].size + 1; }

    void push(int now) {
        swap(tree[now].left, tree[now].right);
        tree[tree[now].left].isReverse ^= 1;
        tree[tree[now].right].isReverse ^= 1;
        tree[now].isReverse = false;
    }

    void split(int cur, int size, int& x, int& y) {
        if (!cur) {
            x = y = 0;
        } else {
            if (tree[cur].isReverse) {
                push(cur);
            }
            if (tree[tree[cur].left].size < size) {
                x = cur;
                split(tree[cur].right, size - tree[tree[cur].left].size - 1, tree[cur].right, y);
            } else {
                y = cur;
                split(tree[cur].left, size, x, tree[cur].left);
            }
            update(cur);
        }
    }

    // 中序遍历
    vector<int> Inorder;
    void InorderTraversal(int cur) {
        if (!cur) {
            return;
        }
        if (tree[cur].isReverse) {
            push(cur);
        }
        InorderTraversal(tree[cur].left);
        Inorder.emplace_back(tree[cur].val);
        InorderTraversal(tree[cur].right);
    }

public:
    int newNode(int val) {
        cnt++;
        tree[cnt].val = val;
        tree[cnt].key = rnd();
        tree[cnt].size = 1;
        return cnt;
    }
    // x 树中的值不大于 y 树中的值
    int merge(int x, int y) {
        if (!x || !y) {
            return x + y;
        }
        if (tree[x].key < tree[y].key) {
            if (tree[x].isReverse) {
                push(x);
            }
            tree[x].right = merge(tree[x].right, y);
            update(x);
            return x;
        } else {
            if (tree[y].isReverse) {
                push(y);
            }
            tree[y].left = merge(x, tree[y].left);
            update(y);
            return y;
        }
    }
    // [l >= 1, r]
    void reverse(int l, int r) {
        int x, y, z;
        split(root, l - 1, x, y);
        split(y, r - l + 1, y, z);
        tree[y].isReverse ^= 1;
        root = merge(merge(x, y), z);
    }

    vector<int> snapshot(int cur = root) {
        Inorder.clear();
        InorderTraversal(cur);
        return Inorder;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    Seg_Treap f(n + 1);
    for (int i = 1; i <= n; ++i) {
        root = f.merge(root, f.newNode(i));
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        f.reverse(l, r);
    }

    for (int& v : f.snapshot()) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}