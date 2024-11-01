#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include "headers.hpp"

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = head;
        for (auto cur = head->next; cur->next; cur = cur = cur->next) {
            if (cur->val) {
                node->val += cur->val;
            } else {
                node = node->next;
                node->val = 0;
            }
        }
        node->next = nullptr;
        return head;
    }
};

int main() {
    Solution sol;

    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
