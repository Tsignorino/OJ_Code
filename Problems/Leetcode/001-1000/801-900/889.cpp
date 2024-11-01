#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // preorder 根 左 右    postorder 左 右 根
        // 只知道前序和后序，无法唯一确定二叉树
        int n = preorder.size();
        unordered_map<int, int> ump;
        for (int i = 0; i < n; ++i) {
            ump[postorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int prel, int prer, int postl, int postr) -> TreeNode* {
            if (prel == prer) {
                return nullptr;
            }
            if (prel + 1 == prer) {
                return new TreeNode(preorder[prel]);
            }

            int ls = ump[preorder[prel + 1]] - postl + 1;
            TreeNode* left = dfs(prel + 1, prel + 1 + ls, postl, postl + ls);
            TreeNode* right = dfs(prel + 1 + ls, prer, postl + ls, postr - 1);
            return new TreeNode(preorder[prel], left, right);
        };

        return dfs(0, n, 0, n);
    }
};