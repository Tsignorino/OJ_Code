#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n);
        stack<int> stk;
        // for (int i = 0; i < n; ++i) {
        //     while (!stk.empty() && t[i] > t[stk.top()]) {
        //         ans[stk.top()] = i - stk.top();
        //         stk.pop();
        //     }
        //     stk.push(i);
        // }

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && t[i] >= t[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            stk.emplace(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> t {73, 74, 75, 71, 69, 72, 76, 73};
    for (int v : sol.dailyTemperatures(t)) {
        cout << v << " ";
    }

    return 0;
}