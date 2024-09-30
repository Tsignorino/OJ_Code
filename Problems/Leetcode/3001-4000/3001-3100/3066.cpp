#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        // ranges::sort(nums);

        priority_queue<i64, vector<i64>, greater<i64>> q;
        for (int& num : nums) {
            q.emplace(num);
        }

        int cnt = 0;
        while (q.top() < k) {
            i64 v1 = q.top();
            q.pop();
            i64 v2 = q.top();
            q.pop();

            q.emplace(v1 * 2LL + v2);
            cnt++;
        }

        return cnt;
    }
};
