#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    暴力重构
*/
// https://oi-wiki.org/ds/sgt/
// https://riteme.site/blog/2016-4-6/scapegoat.html
struct Node {
    int left, right;
    int val;
    int size;
    int realsize; // 以当前节点为根的树的大小和实际大小（未被标记的节点数量）
    bool exist; // 存在标记
};

vector<Node> tree;
int cnt = 0, root = 0;
const double alpha = 0.75;

void newNode(int& now, int val) {
    now = ++cnt;
    tree[now].val = val;
    tree[now].size = tree[now].realsize = 1;
    tree[now].exist = true;
}

bool imbalance(int now) {
    return (max(tree[tree[now].left].size, tree[tree[now].right].size) > tree[now].size * alpha || tree[now].size - tree[now].realsize > tree[now].size * 0.3);
}

vector<int> Inorder;
void InorderTraversal(int now) {
    if (!now) {
        return;
    }
    InorderTraversal(tree[now].left);
    if (tree[now].exist) {
        Inorder.emplace_back(now);
    }
    InorderTraversal(tree[now].right);
}

void lift(int l, int r, int& now) {
    if (l == r) {
        now = Inorder[l];
        tree[now].left = tree[now].right = 0;
        tree[now].size = tree[now].realsize = 1;
        return;
    }
    int m = l + (r - l) / 2;
    while (m && l < m && tree[Inorder[m]].val == tree[Inorder[m - 1]].val) {
        m--;
    }
    now = Inorder[m];
    if (l < m) {
        lift(l, m - 1, tree[now].left);
    } else {
        tree[now].left = 0;
    }
    lift(m + 1, r, tree[now].right);
    tree[now].size = tree[tree[now].left].size + tree[tree[now].right].size + 1;
    tree[now].realsize = tree[tree[now].left].realsize + tree[tree[now].right].realsize + 1;
}

void rebuild(int& now) { // 暴力：中序遍历后分治建树
    Inorder.clear();
    InorderTraversal(now);
    if (Inorder.empty()) {
        now = 0;
        return;
    }
    lift(0, Inorder.size() - 1, now);
}

void update(int& now, int end) {
    if (!now) {
        return;
    }
    if (tree[end].val < tree[now].val) {
        update(tree[now].left, end);
    } else {
        update(tree[now].right, end);
    }
    tree[now].size = tree[tree[now].left].size + tree[tree[now].right].size + 1;
}

// 需要重构的条件： 当前节点的左子树或右子树的大小大于当前节点的大小乘上平衡因子 alpha（0.5 <= alpha <= 1）
void check(int& now, int end) {
    if (now == end) {
        return;
    }
    if (imbalance(now)) {
        rebuild(now);
        update(root, now);
        return;
    }
    if (tree[end].val < tree[now].val) {
        check(tree[now].left, end);
    } else {
        check(tree[now].right, end);
    }
}

void insert(int& now, int val) {
    if (!now) {
        newNode(now, val);
        check(root, now);
    } else {
        tree[now].size++;
        tree[now].realsize++;

        if (val < tree[now].val) {
            insert(tree[now].left, val);
        } else {
            insert(tree[now].right, val);
        }
    }
}

void del(int now, int val) { // 惰性删除（要求树中有该元素）
    if (tree[now].exist && tree[now].val == val) {
        tree[now].exist = false;
        tree[now].realsize--;
        check(root, now);
    } else {
        tree[now].realsize--;
        if (val < tree[now].val) {
            del(tree[now].left, val);
        } else {
            del(tree[now].right, val);
        }
    }
}

int getRank(int val) { // 比当前数小的数的个数加 1
    int now = root, rank = 1;
    while (now) {
        if (val <= tree[now].val) {
            now = tree[now].left;
        } else {
            rank += tree[now].exist + tree[tree[now].left].realsize;
            now = tree[now].right;
        }
    }
    return rank;
}

int getNum(int rank) {
    int now = root;
    while (now) {
        if (tree[now].exist && tree[tree[now].left].realsize + tree[now].exist == rank) {
            break;
        } else if (tree[tree[now].left].realsize >= rank) {
            now = tree[now].left;
        } else {
            rank -= tree[tree[now].left].realsize + tree[now].exist;
            now = tree[now].right;
        }
    }
    return tree[now].val;
}

int getPre(int x) {
    return getNum(getRank(x) - 1);
}
int getPost(int x) {
    return getNum(getRank(x + 1));
}

auto init = []() {
    const int MX = 1e5 + 5;
    tree.resize(MX);
    return 0;
}();

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int Op, x;
        cin >> Op >> x;

        switch (Op) {
            case 1: insert(root, x); break;
            case 2: del(root, x); break;
            case 3: cout << getRank(x) << "\n"; break;
            case 4: cout << getNum(x) << "\n"; break;
            case 5: cout << getPre(x) << "\n"; break;
            case 6: cout << getPost(x) << "\n"; break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}