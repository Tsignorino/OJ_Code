#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class FindElements_1 {
private:
    unordered_set<int> set;

    void dfs(TreeNode* node, int val) {
        if (node == nullptr) {
            return;
        }

        set.insert(val);
        dfs(node->left, val * 2 + 1);
        dfs(node->right, val * 2 + 2);
    }

public:
    FindElements_1(TreeNode* root) { dfs(root, 0); }

    bool find(int target) { return set.contains(target); }
};

class FindElements_2 {
private:
    TreeNode* root;

public:
    FindElements_2(TreeNode* root) : root(root) {}

    bool find(int target) {
        target++;
        auto cur = root;
        for (int i = 30 - __builtin_clz(target); i >= 0; --i) {
            int bit = target >> i & 1;
            cur = bit ? cur->right : cur->left;
            if (cur == nullptr) {
                return false;
            }
        }
        return true;
    }
};