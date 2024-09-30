#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;

            while (num) {
                sum -= num % 10;
                num /= 10;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;

    return 0;
}