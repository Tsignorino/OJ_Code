#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> res(nums);
        res.erase(unique(res.begin(), res.end()), res.end());
        return count(res.begin(), res.end(), 0) * 2 - (res.back() == 0);
    }
};

int main() {
    Solution sol;

    return 0;
}