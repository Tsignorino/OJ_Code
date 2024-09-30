#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr || original == target) {
            return cloned;
        }

        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) {
            return left;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};