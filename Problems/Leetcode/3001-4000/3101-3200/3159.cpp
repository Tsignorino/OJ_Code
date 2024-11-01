#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> vec;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                vec.emplace_back(i);
            }
        }

        vector<int> ans;
        for (int& q : queries) {
            ans.emplace_back(q > vec.size() ? -1 : vec[q - 1]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}