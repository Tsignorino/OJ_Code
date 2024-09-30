#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* fa = nullptr;
        int d = 0;
        bool ans = false;

        function<bool(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* node, TreeNode* father, int depth) -> bool {
            if (node == nullptr || d && depth > d) { // optimization: 已经找到 x 或 y，无需寻找深度超过 d 的节点
                return false;
            }

            // 如果 node 的节点值等于 x 或者 y：
            //      如果之前没有找到 x 也没有找到 y，那么记录 node 的深度到变量 depth 中，记录 node 的父节点到变量 father 中。
            //      如果之前找到 x, y 其中一个，说明现在 x 和 y 都找到了。如果 depth 相同且父节点不同，说明 x 和 y 对应的节点是堂兄弟节点，否则不是。
            if (node->val == x || node->val == y) {
                if (d) {
                    ans = depth == d && father != fa;
                    return true; // optimization: 已经找到 x 和 y，无需继续递归
                }

                d = depth;
                fa = father;
            }

            return dfs(node->left, node, depth + 1) || dfs(node->right, node, depth + 1);
        };

        dfs(root, nullptr, 1);
        return ans;
    }
};