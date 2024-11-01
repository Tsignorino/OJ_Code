#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    // 二叉树的 垂序遍历
    // 列排序、深度排序、值排序
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> vec; // [key, depth, val]

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int k, int y) -> void {
            if (node == nullptr) {
                return;
            }

            dfs(node->left, k + 1, y - 1);
            vec.emplace_back(y, k, node->val);
            dfs(node->right, k + 1, y + 1);
        };

        dfs(root, 0, 0);

        ranges::sort(vec);

        int minV = get<0>(vec[0]), maxV = get<0>(vec[vec.size() - 1]);
        vector<vector<int>> ans(maxV - minV + 1);
        for (const auto& v : vec) {
            ans[get<0>(v) - minV].emplace_back(get<2>(v));
        }

        return ans;

        // int lastcol = INT_MIN;
        // for (const auto& [col, _, value] : vec) {
        //     if (col != lastcol) {
        //         lastcol = col;
        //         ans.emplace_back();
        //     }
        //     ans.back().push_back(value);
        // }
        // return ans;
    }
};