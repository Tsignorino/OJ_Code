#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int cnt = q.size();
            ans.emplace_back(vector<int>());

            while (cnt--) {
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
        return ans;
    }
};