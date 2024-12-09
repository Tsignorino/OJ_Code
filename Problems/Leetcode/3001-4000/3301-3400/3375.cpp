#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for (int& v : nums) {
            if (v < k) {
                return -1;
            }
            if (v > k) {
                s.emplace(v);
            }
        }
        return s.size();
    }
};

int main() {
    Solution sol;

    return 0;
}