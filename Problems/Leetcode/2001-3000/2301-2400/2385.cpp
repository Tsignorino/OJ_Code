#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;

class Solution {
    int ans = 0, start;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int l_len = dfs(node->left);
        int r_len = dfs(node->right);
        if (node->val == start) {
            ans = -min(l_len, r_len);
            return 1;
        }
        if (l_len > 0 || r_len > 0) {
            ans = max(ans, abs(l_len) + abs(r_len));
            return max(l_len, r_len) + 1;
        }
        return min(l_len, r_len) - 1;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        dfs(root);
        return ans;
    }
};

class Solution_1 {
    int ans = 0, start;

    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, false};
        }

        auto [l_len, l_found] = dfs(node->left);
        auto [r_len, r_found] = dfs(node->right);
        if (node->val == start) {
            ans = max(l_len, r_len);
            return {1, true};
        }
        if (l_found || r_found) {
            ans = max(ans, l_len + r_len);
            return {(l_found ? l_len : r_len) + 1, true};
        }
        return {max(l_len, r_len) + 1, false};
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        dfs(root);
        return ans;
    }
};

TreeNode* pa[100001];

class Solution_2 {
public:
    int start;
    TreeNode* start_node;

    void dfs(TreeNode* node, TreeNode* from) {
        if (node == nullptr) {
            return;
        }

        pa[node->val] = from; // 记录父节点
        if (node->val == start) {
            start_node = node;
        }
        dfs(node->left, node);
        dfs(node->right, node);
    }

    int maxDepth(TreeNode* node, TreeNode* from) {
        if (node == nullptr) {
            return -1;
        }

        int res = -1;
        if (node->left != from) {
            res = max(res, maxDepth(node->left, node));
        }
        if (node->right != from) {
            res = max(res, maxDepth(node->right, node));
        }
        if (pa[node->val] != from) {
            res = max(res, maxDepth(pa[node->val], node));
        }
        return res + 1;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        dfs(root, nullptr);
        return maxDepth(start_node, start_node);
    }
};