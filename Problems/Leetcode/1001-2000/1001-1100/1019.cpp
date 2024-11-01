#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        for (auto cur = head; cur; cur = cur->next) {
            while (!stk.empty() && cur->val > ans[stk.top()]) {
                ans[stk.top()] = cur->val;
                stk.pop();
            }
            stk.push(ans.size());
            ans.emplace_back(cur->val);
        }

        while (!stk.empty()) {
            ans[stk.top()] = 0;
            stk.pop();
        }

        return ans;
    }
};