#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == nullptr) {
            return ans;
        }
        q.emplace(root);

        while (!q.empty()) {
            int size = q.size();
            ans.emplace_back(vector<int>());

            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                ans.back().emplace_back(node->val);
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};