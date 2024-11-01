#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[n - mid] >= mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;

    vector<int> citations {0, 1, 3, 5, 6};
    cout << sol.hIndex(citations);

    return 0;
}