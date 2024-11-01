#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            int cnt = q.size();
            long long total = 0;
            while (cnt--) {
                TreeNode* node = q.front();
                q.pop();
                total += node->val;

                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
            res.emplace_back(total);
        }

        // if (res.size() < k) {
        //     return -1;
        // }
        // ranges::sort(res, greater<long long>());
        // return res[k - 1];

        int n = res.size();
        if (n < k) {
            return -1;
        }
        ranges::nth_element(res, res.begin() + (n - k));
        return res[n - k];
    }
};