#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for (const int& num : nums) {
            ans += num;
            cnt += ans == 0;
        }
        return cnt;
    }
};