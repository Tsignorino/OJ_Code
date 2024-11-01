#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) {
            return nullptr;
        }

        int leftSize = ranges::find(inorder, postorder.back()) - inorder.begin();
        vector<int> inleft(inorder.begin(), inorder.begin() + leftSize);
        vector<int> inright(inorder.begin() + leftSize + 1, inorder.end());
        vector<int> postleft(postorder.begin(), postorder.begin() + leftSize);
        vector<int> postright(postorder.begin() + leftSize, postorder.end() - 1);

        TreeNode* left = buildTree(inleft, postleft);
        TreeNode* right = buildTree(inright, postright);
        return new TreeNode(postorder.back(), left, right);
    }

    TreeNode* buildTree_1(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> ump;
        for (int i = 0; i < n; ++i) {
            ump[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int inleft, int inright, int postleft, int postright) -> TreeNode* {
            if (postleft == postright) {
                return nullptr;
            }

            int leftSize = ump[postorder[postright - 1]] - inleft;
            TreeNode* left = dfs(inleft, inleft + leftSize, postleft, postleft + leftSize);
            TreeNode* right = dfs(inleft + leftSize + 1, inright, postleft + leftSize, postright - 1);
            return new TreeNode(postorder[postright - 1], left, right);
        };

        return dfs(0, n, 0, n);
    }
};