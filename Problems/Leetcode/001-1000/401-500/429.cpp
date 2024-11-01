#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            int cnt = q.size();
            Node* node;
            ans.emplace_back(vector<int>());
            while (cnt--) {
                node = q.front();
                q.pop();
                ans.back().emplace_back(node->val);

                for (const auto& n : node->children) {
                    q.emplace(n);
                }
            }
        }

        return ans;
    }
};