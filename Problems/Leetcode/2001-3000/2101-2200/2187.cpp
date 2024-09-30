#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& nums, int k) {
        int n = nums.size();
        long long l = 0;
        // long long r = 1e14 + 1;
        long long r = *min_element(nums.begin(), nums.end()) * 1LL * k;
        while (l + 1 < r) {
            long long mid = l + (r - l) / 2;

            long long cnt = 0;
            for (const int& num : nums) {
                cnt += mid / num;
            }

            if (cnt >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};

int main() {
    Solution sol;

    vector<int> time {1, 2, 3};
    int totalTrips = 5;
    cout << sol.minimumTime(time, totalTrips);

    return 0;
}