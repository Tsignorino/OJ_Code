#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;

        auto dfs = [&](auto self, TreeNode* node, int minV, int maxV) {
            if (node == nullptr) {
                ans = max(ans, maxV - minV);
                return;
            }

            minV = min(minV, node->val);
            maxV = max(maxV, node->val);
            self(self, node->left, minV, maxV);
            self(self, node->right, minV, maxV);
        };

        dfs(dfs, root, root->val, root->val);
        return ans;
    }
};