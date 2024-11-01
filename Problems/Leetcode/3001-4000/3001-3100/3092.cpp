#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 哈希 + 懒删除堆
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, long long> cnt;
        priority_queue<pair<long long, int>> q; // (cnt[x], x)
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            cnt[x] += freq[i];
            q.emplace(cnt[x], x);

            while (q.top().first != cnt[q.top().second]) { // 堆顶数据变化
                q.pop();
            }

            ans[i] = q.top().first;
        }

        return ans;
    }

public:
    // 哈希 + 有序集合
    vector<long long> mostFrequentIDs_1(vector<int>& nums, vector<int>& freq) {
        // 输入保证任何操作后，集合中的元素出现次数不会为负数
        // freq[i] != 0
        vector<long long> ans;
        unordered_map<int, long long> ump;
        multiset<long long> set;
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            auto iter = set.find(ump[val]);
            if (iter != set.end()) {
                set.erase(iter);
            }

            ump[val] += freq[i];
            set.insert(ump[val]);

            ans.emplace_back(*set.rbegin());
        }
        return ans;
    }
};

int main() {
    vector<int> nums {2, 3, 2, 1}, freq {3, 2, -3, 1};

    Solution sol;
    vector<long long> ans = sol.mostFrequentIDs(nums, freq);

    return 0;
}