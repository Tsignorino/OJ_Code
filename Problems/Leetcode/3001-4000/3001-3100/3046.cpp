#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (int& num : nums) {
            if (++ump[num] > 2) {
                return false;
            }
        }
        return true;
    }
};