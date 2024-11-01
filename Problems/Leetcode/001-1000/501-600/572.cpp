#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
private:
    bool check(TreeNode* o, TreeNode* t) {
        if (o == nullptr && t == nullptr) {
            return true;
        }
        if (o == nullptr && t != nullptr || o != nullptr && t == nullptr || o->val != t->val) {
            return false;
        }
        return check(o->left, t->left) && check(o->right, t->right);
    }

    bool dfs(TreeNode* o, TreeNode* t) {
        if (o == nullptr) {
            return false;
        }
        return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { return dfs(root, subRoot); }
};

int main() {
    Solution sol;

    return 0;
}