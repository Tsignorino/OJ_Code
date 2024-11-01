#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 1;
        function<int(TreeNode*)> func = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            int l = func(node->left);
            int r = func(node->right);
            cnt = max(cnt, l + r + 1);

            return max(l, r) + 1;
        };

        func(root);

        return cnt - 1;
    }
};