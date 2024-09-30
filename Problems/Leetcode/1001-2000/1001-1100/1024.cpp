#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        /*
            贪心
        */
        vector<int> mx(time);
        for (auto& vec : clips) {
            if (vec[0] < time) {
                mx[vec[0]] = max(mx[vec[0]], vec[1]);
            }
        }

        int ans = 0, last = 0, pre = 0;
        for (int i = 0; i < time; ++i) {
            last = max(last, mx[i]);

            if (i == last) { // 下一个位置无法被覆盖
                return -1;
            }

            if (i == pre) {
                ans++;
                pre = last;
            }
        }
        return ans;

        /*
            DP
        */
        // vector<int> dp(time + 1, INT_MAX / 2);
        // dp[0] = 0;
        // for (int i = 1; i <= time; ++i) {
        //     for (auto& vec : clips) {
        //         if (vec[0] < i && i <= vec[1]) {
        //             dp[i] = min(dp[i], dp[vec[0]] + 1);
        //         }
        //     }
        // }
        // return dp[time] == INT_MAX / 2 ? -1 : dp[time];
    }
};

int main() {
    Solution sol;

    return 0;
}