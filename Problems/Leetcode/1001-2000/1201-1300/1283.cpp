#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int calc(vector<int>& nums, int mid) {
        int ans = 0;
        for (const int& num : nums) {
            // ans += (num + mid - 1) / mid;
            // ans += ceil(num * 1.0 / mid);
            ans += (num - 1) / mid + 1;
        }
        return ans;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 0, r = 1e6 + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (calc(nums, mid) > threshold) {
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

    vector<int> nums {1, 2, 5, 9};
    int threshold = 6;
    cout << sol.smallestDivisor(nums, threshold);

    return 0;
}