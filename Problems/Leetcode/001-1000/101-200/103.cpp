#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    //* 反转
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> temp;
            while (cnt--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
                temp.emplace_back(node->val);
            }
            if (ans.size() % 2) {
                ranges::reverse(temp);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }

    //* 双端队列
    vector<vector<int>> _zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        deque<TreeNode*> dq;
        dq.emplace_back(root);
        bool flag = true;
        while (!dq.empty()) {
            int cnt = dq.size();
            ans.emplace_back(vector<int>());

            TreeNode* node;
            while (cnt--) {
                if (flag) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) {
                        dq.emplace_back(node->left);
                    }
                    if (node->right) {
                        dq.emplace_back(node->right);
                    }
                } else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right) {
                        dq.emplace_front(node->right);
                    }
                    if (node->left) {
                        dq.emplace_front(node->left);
                    }
                }
                ans.back().emplace_back(node->val);
            }
            flag = !flag;
        }
        return ans;
    }
};