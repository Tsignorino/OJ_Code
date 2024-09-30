#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int func1(int x) {
    int cnt = 0;
    while (x) {
        // cnt += x % 2;
        // x /= 2;

        x &= x - 1;
        cnt++;
    }
    return cnt;
}

// 10 位二进制数
int func2(int x) {
    x = (x & 0b01'0101'0101) + ((x & 0b10'1010'1010) >> 1);
    x = ((x & 0b00'1100'1100) >> 2) + (x & 0b11'0011'0011);
    x = (x >> 8) + ((x >> 4) & 0b1111) + (x & 0b1111);
    return x;
}

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {5, 10, 1, 5, 2};
    int k = 1;
    cout << sol.sumIndicesWithKSetBits(nums, k);

    return 0;
}