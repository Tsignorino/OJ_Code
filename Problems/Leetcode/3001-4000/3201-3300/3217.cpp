#include <bits/stdc++.h>

using namespace std;

#include "headers.hpp"

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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> set(nums.begin(), nums.end());

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr) {
            if (set.contains(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

public:
    ListNode* racing_modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> ump;
        for (int& num : nums) {
            ump[num]++;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;

        vector<int> vec;
        while (head != nullptr) {
            vec.emplace_back(head->val);
            head = head->next;
        }

        for (int& v : vec) {
            if (ump[v]) {
                continue;
            }
            ListNode* node = new ListNode(v);
            cur->next = node;
            cur = node;
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;

    return 0;
}