#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& nums, double hour) {
        int n = nums.size();

        //* 避免浮点数误差
        long long k = llround(hour * 100);
        if (k <= (n - 1) * 100) {
            return -1;
        }

        // 二分时速
        int l = 0, r = 1e7 + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;

            long long total = 0; // 计算路程
            for (int i = 0; i < n - 1; ++i) {
                total += (nums[i] + mid - 1) / mid * mid;
            }
            total += nums[n - 1];

            // total * 100 * 1.0 / mid 和 k 比较
            if (total * 100 > k * mid) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return r;
    }
};

int main() {
    Solution sol;

    // vector<int> dist {1, 3, 2};
    // double hour = 6;
    // double hour = 1.9;

    vector<int> dist {1, 1, 100000};
    double hour = 2.01;
    cout << sol.minSpeedOnTime(dist, hour);

    return 0;
}