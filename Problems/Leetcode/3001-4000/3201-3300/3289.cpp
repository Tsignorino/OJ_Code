#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> mp;
        for (int& v : nums) {
            mp[v]++;
        }

        vector<int> ans;
        for (auto& [v, c] : mp) {
            if (c == 2) {
                ans.emplace_back(v);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}