#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        array<int, 2> sum;
        int n = customers.size();
        int maxV = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            sum[grumpy[r]] += customers[r];
            if (r - l + 1 < minutes) {
                continue;
            }

            maxV = max(maxV, sum[1]);
            sum[1] -= grumpy[l] ? customers[l] : 0;
            l++;
        }
        return sum[0] + maxV;
    }
};

class mySolution {
public:
    //* 前后缀分解
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + (grumpy[i] == 0 ? customers[i] : 0);
        }

        vector<int> preSum(n + 1);
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + customers[i];
            pre[i + 1] = pre[i] + (grumpy[i] == 0 ? customers[i] : 0);
        }

        int ans = 0;
        for (int i = 0; i < n - minutes + 1; ++i) {
            int j = i + minutes;
            ans = max(ans, pre[i] + suf[j] + preSum[j] - preSum[i]);
        }
        return ans;
    }

public:
    //* 滑窗
    int maxSatisfied_(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += grumpy[i] == 0 ? customers[i] : 0;
        }

        int res = 0;
        for (int i = 0; i < minutes; ++i) {
            res = grumpy[i] == 1 ? customers[i] : 0;
        }

        int ret = res;
        for (int l = 0, r = minutes; r < n; ++r, ++l) {
            ret += grumpy[r] == 1 ? customers[r] : 0;
            ret -= grumpy[l] == 1 ? customers[l] : 0;
            res = max(res, ret);
        }

        return sum + res;
    }
};