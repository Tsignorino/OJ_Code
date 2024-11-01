#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        if (root->left == root->right) {
            return to_string(root->val);
        }
        if (root->right == nullptr) {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};

int main() {
    Solution sol;

    return 0;
}