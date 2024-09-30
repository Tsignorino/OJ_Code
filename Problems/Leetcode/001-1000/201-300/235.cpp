#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
private:
    vector<TreeNode*> path(TreeNode* node, int val) {
        vector<TreeNode*> p;
        while (node->val != val) {
            p.emplace_back(node);

            if (node->val > val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        p.emplace_back(node);
        return p;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto v1 = path(root, p->val), v2 = path(root, q->val);

        TreeNode* ans;
        for (int i = 0; i < min(v1.size(), v2.size()); ++i) {
            if (v1[i] == v2[i]) {
                ans = v1[i];
            }
        }

        return ans;
    }
};