#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

const int inf = 2147483647; // 标志

struct BST {
    struct Node {
        Node* left = 0;
        Node* right = 0;
        int val = 0, lcnt = 0, rcnt = 0;
        Node(int val) : val(val) {}
    }* root = nullptr;

private:
    vector<int> Inorder;
    void dfs(Node* now) {
        if (!now) return;
        dfs(now->left);
        Inorder.push_back(now->val);
        dfs(now->right);
    }

    void insert(Node*& now, int key) {
        if (!now) {
            now = new Node(key);
            return;
        }
        if (now->val <= key) {
            insert(now->right, key);
            now->rcnt++;
        } else {
            insert(now->left, key);
            now->lcnt++;
        }
    }
    bool findKey(Node* now, int key) {
        if (!now) return false;
        if (now->val == key) return true;
        if (now->val < key) {
            return findKey(now->right, key);
        }
        return findKey(now->left, key);
    }
    int getNum(Node* now, int x) {
        if (!now) return inf;
        int tmp = now->lcnt + 1;
        if (tmp == x) return now->val;
        if (tmp < x) {
            return getNum(now->right, (x - tmp));
        }
        return getNum(now->left, x);
    }
    int getRank(Node* now, int x, int K = 0) {
        if (!now) return K;
        if (now->val == x) return K + now->lcnt + 1;
        if (now->val < x) {
            return getRank(now->right, x, K + (now->lcnt + 1));
        }
        return getRank(now->left, x, K);
    }

public:
    void insert(int key) { insert(root, key); }
    bool findKey(int key) { return findKey(root, key); }
    int getNum(int x) { return getNum(root, x); }
    int getRank(int x) { return getRank(root, x); }
    int getPre(int key) {
        int ret = -inf;
        Node* p = root;
        while (p) {
            if (key > (p->val)) {
                ret = p->val;
                p = p->right;
            } else {
                p = p->left;
            }
        }
        return ret;
    }
    int getNxt(int key) {
        int ret = inf;
        Node* p = root;
        while (p) {
            if (key < p->val) {
                ret = p->val;
                p = p->left;
            } else {
                p = p->right;
            }
        }
        return ret;
    }

    vector<int> snapshot(Node* now) {
        Inorder.clear();
        dfs(now);
        return Inorder;
    }
};

void solve() {
    int q;
    cin >> q;

    BST f;

    while (q--) {
        int Op, x;
        cin >> Op >> x;

        switch (Op) {
            case 1: cout << f.getRank(x) + 1 << "\n"; break;
            case 2: cout << f.getNum(x) << "\n"; break;
            case 3: cout << f.getPre(x) << "\n"; break;
            case 4: cout << f.getNxt(x) << "\n"; break;
            case 5: f.insert(x); break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}