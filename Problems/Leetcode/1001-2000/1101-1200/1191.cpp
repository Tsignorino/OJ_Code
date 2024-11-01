#include <bits/stdc++.h>

using namespace std;

/*
! 首先对于题目的理解从 "考虑 1 个数组，考虑 2 个数组，考虑 k 个数组" 转换成 "取整个数组，取原数组的一部分"

! WA: arr = [1, 2], k = 1
    两个数组的时候，没有判断 k 值
! WA: arr = [-5,-2,0,0,3,9,-2,-5,4], k = 5
    不是去掉前后缀负值，而是处理开头结尾对结果的负面影响
! WA:
    没有对 2 个数组的情况进行取模
*/

class Solution {
    static constexpr int mod = 1e9 + 7;

public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long cur = 0, sum = 0, maxSum = 0;
        for (int x : arr) {
            sum += x;
            cur = max(0ll, cur) + x;
            maxSum = max(maxSum, cur);
        }
        if (k == 1) {
            return maxSum % mod;
        }

        for (int x : arr) {
            cur = max(0ll, cur) + x;
            maxSum = max(maxSum, cur);
        }
        if (k == 2) {
            return maxSum % mod;
        }

        return sum > 0 ? ((k - 2) * sum + maxSum) % mod : maxSum % mod;
    }

public:
    int mykConcatenationMaxSum(vector<int>& arr, int k) {
        int ans = 0;
        int sum1 = accumulate(arr.begin(), arr.end(), 0);

        // 如果 sum1 > 0，考虑 k 个串联的情况
        // （处理开头结尾的影响，即 '数组的元素和' 减去 '最大连续子数组的和'）
        long long sum2 = (k - 1) * 1ll * sum1 % mod;
        int res = 0, f = 0;
        for (int v : arr) {
            f = max(f, 0) + v;
            res = max(res, f);
        }
        sum2 += res;

        ans = max(ans, int(sum2 % mod));

        // 如果 sum1 <= 0，只能取原数组的一部分，考虑两个串联的情况（k > 1）
        if (k > 1) {
            int res = 0, f = 0;
            int n = arr.size();
            for (int i = 0; i < 2 * n; ++i) {
                f = max(f, 0) + arr[i % n];
                res = max(res, f);
            }
            ans = max(ans, res % mod);
        }

        return ans;
    }
};