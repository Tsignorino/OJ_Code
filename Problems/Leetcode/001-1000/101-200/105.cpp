#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> myBuildTree = [&](int preorder_left, int preorder_right, int inorder_left, int inorder_right) -> TreeNode* {
            if (preorder_left > preorder_right) {
                return nullptr;
            }

            int preorder_root = preorder_left; // 在前序遍历中记录根节点
            int inorder_root = index[preorder[preorder_root]]; // 在中序遍历中定位根节点

            TreeNode* root = new TreeNode(preorder[preorder_root]);

            int size_left_subtree = inorder_root - inorder_left; // 左子树中的节点数目

            root->left = myBuildTree(preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
            root->right = myBuildTree(preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);

            return root;
        };

        return myBuildTree(0, n - 1, 0, n - 1);
    }
};
