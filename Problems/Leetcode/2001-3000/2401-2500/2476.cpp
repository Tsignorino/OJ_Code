#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
    vector<int> vec;

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        vec.emplace_back(node->val);
        dfs(node->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);

        int n = vec.size();
        vector<vector<int>> ans;
        for (int& q : queries) {
            int idx = ranges::lower_bound(vec, q) - vec.begin();
            int maxV = idx < n ? vec[idx] : -1;

            if (idx == n || vec[idx] != q) {
                idx--;
            }
            int minV = idx >= 0 ? vec[idx] : -1;

            ans.push_back({minV, maxV});
            // ans.emplace_back(vector<int>{minV, maxV});
        }

        return ans;
    }
};