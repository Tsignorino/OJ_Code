#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // 二叉树的最大路径和 = 左子树的最大路径和 + 右子树的最大路径和 + 当前节点的值
        int ans = -1001;

        // 当前节点的最大链和 = max(左子树的最大链和, 右子树的最大链和) + 当前节点的值
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            int l_sum = dfs(node->left);
            int r_sum = dfs(node->right);

            ans = max(ans, l_sum + r_sum + node->val);

            return max(max(l_sum, r_sum) + node->val, 0);
        };

        dfs(root);
        return ans;
    }
};