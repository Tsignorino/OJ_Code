#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> f;
        for (int& v : nums) {
            auto iter = ranges::upper_bound(f, v);
            if (iter == f.end()) {
                f.emplace_back(v);
            } else {
                *iter = v;
            }
        }
        return nums.size() - f.size();
    }
};

int main() {
    Solution sol;

    return 0;
}