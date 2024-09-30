#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        // 拿出，不能放回；让剩下的非空袋子豆子数量相等
        sort(beans.begin(), beans.end());

        // 前缀和
        // 4 1 6 5  -->  1 4 5 6  -->  0 1 5 10 16
        // 比当前数大的可以选择减少，比当前数小的可以选择全拿走
        // int n = beans.size();
        // vector<long long> preSum(n + 1);
        // for (int i = 0; i < n; ++i) {
        //     preSum[i + 1] = preSum[i] + beans[i];
        // }
        //
        // long long ans = 1e11;
        // for (int i = 0; i < n; ++i) {
        //     ans = min(ans,
        //         preSum[n] - preSum[i + 1] - (long long) beans[i] * (n - i - 1) // 后面需要减少的量
        //         + preSum[i] // 前面需要删除的量
        //     );
        // }
        //
        // return ans;

        // * 因此，拿走豆子的数量： total - beans[i] * n'     n' 表示豆子个数不少于 beans[i] 的袋子数量
        int n = beans.size();
        long long ans = 1e11;
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        for (int i = 0; i < n; ++i) {
            ans = min(ans, total - (long long) beans[i] * (n - i));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}