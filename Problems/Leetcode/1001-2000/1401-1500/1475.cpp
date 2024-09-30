#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //* 从左往右
        // int n = prices.size();
        // vector<int> ans(prices);
        // stack<int> stk;
        // for (int i = 0; i < n; ++i) {
        //     while (!stk.empty() && prices[i] <= prices[stk.top()]) {
        //         ans[stk.top()] = prices[stk.top()] - prices[i];
        //         stk.pop();
        //     }

        //     stk.push(i);
        // }
        // return ans;

        //* 从右往左
        int n = prices.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = n - 1; i > -1; --i) {
            while (!stk.empty() && prices[i] < prices[stk.top()]) {
                stk.pop();
            }

            ans[i] = stk.empty() ? prices[i] : prices[i] - prices[stk.top()];

            stk.push(i);
        }
        return ans;
    }
};