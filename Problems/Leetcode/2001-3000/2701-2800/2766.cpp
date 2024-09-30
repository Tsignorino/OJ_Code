#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> set(nums.begin(), nums.end());
        for (int i = 0; i < moveTo.size(); ++i) {
            set.extract(moveFrom[i]);
            set.emplace(moveTo[i]);
        }
        return vector(set.begin(), set.end());
    }
};

int main() {
    Solution sol;

    return 0;
}