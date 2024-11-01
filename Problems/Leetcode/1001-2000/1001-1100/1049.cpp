#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

//* https://leetcode.cn/problems/last-stone-weight-ii/solutions/818362/gong-shui-san-xie-xiang-jie-wei-he-neng-jgxik/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        // 石头不放回，可划分为两个堆：“正号堆”、“负号堆”
        // 石头放回并不实际产生新的重量，而是选择调整放入哪个堆中
        int sum = reduce(stones.begin(), stones.end());
        int t = sum / 2;
        vector<int> f(t + 1);
        for (int i = 0; i < n; ++i) {
            int v = stones[i];
            for (int j = t; j >= v; --j) {
                f[j] = max(f[j], f[j - v] + v);
            }
        }
        return sum - f[t] * 2;
    }
};

int main() {
    Solution sol;

    return 0;
}