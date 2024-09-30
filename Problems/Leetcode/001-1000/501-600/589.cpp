#include <bits/stdc++.h>

#include "headers.hpp"

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> preorder_0(Node* root) {
        vector<int> ans;

        function<void(Node*)> dfs = [&](Node* root) -> void {
            if (root == nullptr) {
                return;
            }

            ans.emplace_back(root->val);

            for (const auto& node : root->children) {
                dfs(node);
            }
        };

        dfs(root);

        return ans;
    }

public:
    vector<int> preorder_1(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        unordered_map<Node*, int> cnt;
        stack<Node*> stk;
        Node* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                ans.emplace_back(node->val);
                stk.emplace(node);

                if (node->children.size() > 0) {
                    cnt[node] = 0;
                    node = node->children[0];
                } else {
                    node = nullptr;
                }
            }

            node = stk.top();
            int idx = (cnt.count(node) ? cnt[node] : -1) + 1;
            if (idx < node->children.size()) {
                cnt[node] = idx;
                node = node->children[idx];
            } else {
                stk.pop();
                cnt.erase(node);
                node = nullptr;
            }
        }

        return ans;
    }

public:
    vector<int> preorder_2(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        stack<Node*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);

            for (auto iter = node->children.rbegin(); iter != node->children.rend(); ++iter) {
                stk.emplace(*iter);
            }
        }

        return ans;
    }
};