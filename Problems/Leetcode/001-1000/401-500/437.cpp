#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
private:
    //* 计算从该节点开始，满足条件的个数
    int nodeSum(TreeNode* root, long long targetSum) {
        if (root == nullptr) {
            return 0;
        }

        // int res = 0;
        // if (root->val == targetSum) {
        //     res++;
        // }

        // res += nodeSum(root->left, targetSum - root->val);
        // res += nodeSum(root->right, targetSum - root->val);
        // return res;

        return (root->val == targetSum) + nodeSum(root->left, targetSum - root->val) + nodeSum(root->right, targetSum - root->val);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        // int ans = nodeSum(root, targetSum);
        // ans += nodeSum(root->left, targetSum);
        // ans += nodeSum(root->right, targetSum);
        // return ans;
        return nodeSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};