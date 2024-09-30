#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
void print(T vec) {
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for (const int& num : nums) {
            ump[num]++;
        }

        unordered_set<int> s;
        vector<int> ans;
        for (const int& num : nums) {
            s.emplace(num);

            if (--ump[num] == 0) {
                ump.erase(num);
            }

            ans.emplace_back(s.size() - ump.size());
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {3, 2, 3, 4, 2};
    print(sol.distinctDifferenceArray(nums));

    return 0;
}