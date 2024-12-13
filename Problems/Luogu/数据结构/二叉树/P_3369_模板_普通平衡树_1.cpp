#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr double alpha = 0.75;
static int cnt = 0, root = 0;

class Scapegoat {
    struct Node {
        int left, right;
        int val;
        int size;
        int realsize; // 以当前节点为根的树的实际大小（未被标记的节点数量）
        bool exist; // 存在标记
    };

    vector<Node> tree;

public:
    Scapegoat() = default;
    Scapegoat(int size) : tree(size) {}

private:
    int newNode(int& cur, int val) {
        cur = ++cnt;
        tree[cur].val = val;
        tree[cur].size = tree[cur].realsize = 1;
        tree[cur].exist = true;
        return cur;
    }

    bool imbalance(int cur) {
        return (max(tree[tree[cur].left].size, tree[tree[cur].right].size) > tree[cur].size * alpha //
                || tree[cur].size - tree[cur].realsize > tree[cur].size * 0.3);
    }

    // 中序遍历
    vector<int> Inorder;
    void InorderTraversal(int cur) {
        if (!cur) {
            return;
        }
        InorderTraversal(tree[cur].left);
        if (tree[cur].exist) {
            Inorder.emplace_back(cur);
        }
        InorderTraversal(tree[cur].right);
    }

    void lift(int l, int r, int& cur) {
        if (l == r) {
            cur = Inorder[l];
            tree[cur].left = tree[cur].right = 0;
            tree[cur].size = tree[cur].realsize = 1;
            return;
        }
        int m = l + (r - l) / 2;
        // 处理重复数据（一般将相同的数放到右子树）
        while (m && l < m && tree[Inorder[m]].val == tree[Inorder[m - 1]].val) {
            m--;
        }
        cur = Inorder[m];
        if (l < m) {
            lift(l, m - 1, tree[cur].left);
        } else {
            tree[cur].left = 0;
        }
        lift(m + 1, r, tree[cur].right);
        tree[cur].size = tree[tree[cur].left].size + tree[tree[cur].right].size + 1;
        tree[cur].realsize = tree[tree[cur].left].realsize + tree[tree[cur].right].realsize + 1;
    }

    // 暴力：中序遍历后分治建树
    void rebuild(int& cur) {
        Inorder.clear();
        InorderTraversal(cur);
        if (Inorder.empty()) {
            cur = 0;
            return;
        }
        lift(0, Inorder.size() - 1, cur);
    }

    void update(int& cur, int end) {
        if (!cur) {
            return;
        }
        if (tree[end].val < tree[cur].val) {
            update(tree[cur].left, end);
        } else {
            update(tree[cur].right, end);
        }
        tree[cur].size = tree[tree[cur].left].size + tree[tree[cur].right].size + 1;
    }

    // 需要重构的条件： 当前节点的左子树或右子树的大小大于当前节点的大小乘上平衡因子 alpha（0.5 <= alpha <= 1）
    void check(int& cur, int end) {
        if (cur == end) {
            return;
        }
        if (imbalance(cur)) {
            rebuild(cur);
            update(root, cur);
            return;
        }
        if (tree[end].val < tree[cur].val) {
            check(tree[cur].left, end);
        } else {
            check(tree[cur].right, end);
        }
    }

public:
    void insert(int& cur, int val) {
        if (!cur) {
            newNode(cur, val);
            check(root, cur);
        } else {
            tree[cur].size++;
            tree[cur].realsize++;
            if (val < tree[cur].val) {
                insert(tree[cur].left, val);
            } else {
                insert(tree[cur].right, val);
            }
        }
    }
    void del(int cur, int val) { // 惰性删除（要求树中有该元素）
        if (tree[cur].exist && tree[cur].val == val) {
            tree[cur].exist = false;
            tree[cur].realsize--;
            check(root, cur);
        } else {
            tree[cur].realsize--;
            if (val < tree[cur].val) {
                del(tree[cur].left, val);
            } else {
                del(tree[cur].right, val);
            }
        }
    }
    // rank：比当前数小的数的个数加 1
    int getRank(int val) {
        int cur = root, rank = 1;
        while (cur) {
            if (val <= tree[cur].val) {
                cur = tree[cur].left;
            } else {
                rank += tree[cur].exist + tree[tree[cur].left].realsize;
                cur = tree[cur].right;
            }
        }
        return rank;
    }
    int getNum(int rank) {
        int cur = root;
        while (cur) {
            if (tree[cur].exist && tree[tree[cur].left].realsize + tree[cur].exist == rank) {
                break;
            } else if (tree[tree[cur].left].realsize >= rank) {
                cur = tree[cur].left;
            } else {
                rank -= tree[tree[cur].left].realsize + tree[cur].exist;
                cur = tree[cur].right;
            }
        }
        return tree[cur].val;
    }
    int getPre(int x) { return getNum(getRank(x) - 1); }
    int getNxt(int x) { return getNum(getRank(x + 1)); }
};

void solve() {
    int q;
    cin >> q;

    const int MX = 1e5 + 5;
    Scapegoat f(MX);

    while (q--) {
        int Op, x;
        cin >> Op >> x;

        switch (Op) {
            case 1: f.insert(root, x); break;
            case 2: f.del(root, x); break;
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