#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int i, int j) {
            if (nums[i] == nums[j]) {
                return true;
            }

            string s = to_string(nums[i]);
            string t = to_string(nums[j]);
            if (s.size() <= t.size()) {
                swap(s, t);
            }

            int m = s.size();
            for (int p = 0; p < m; ++p) {
                for (int q = p + 1; q < m; ++q) {
                    swap(s[p], s[q]);
                    if (stoi(s) == stoi(t)) {
                        return true;
                    }
                    swap(s[p], s[q]);
                }
            }
            return false;
        };

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cnt += check(i, j);
            }
        }
        return cnt;
    }
};