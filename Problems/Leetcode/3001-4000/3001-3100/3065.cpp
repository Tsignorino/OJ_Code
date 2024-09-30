#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        for (int& num: nums) {
            cnt += num < k;
        }
        return cnt;
    }
};