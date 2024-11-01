#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        ranges::sort(ids, [&](int i, int j) { return wage[i] * quality[j] < wage[j] * quality[i]; });

        int sum = 0; // 维护最小的 k 个 q 值
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            pq.emplace(quality[ids[i]]);
            sum += quality[ids[i]];
        }

        double ans = sum * ((double) wage[ids[k - 1]] / quality[ids[k - 1]]);
        for (int i = k; i < n; ++i) {
            int q = quality[ids[i]];
            if (q < pq.top()) { // q 更小，sum 减小，单位工作质量的薪资增加，但 ans 可能减小
                sum -= pq.top() - q;
                pq.pop();
                pq.emplace(q);
                ans = min(ans, sum * ((double) wage[ids[i]] / q));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}