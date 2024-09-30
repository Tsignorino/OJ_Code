#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = ranges::max(milestones);
        long long others = accumulate(milestones.begin(), milestones.end(), 0ll) - mx;
        return min(others * 2 + 1, mx + others);

        // long long mx = ranges::max(milestones);
        // long long others = accumulate(milestones.begin(), milestones.end(), 0ll) - mx;
        // return min(others + 1, mx) + others;
    }
};

int main() {
    Solution sol;

    vector<int> vec {9, 3, 6, 8, 2, 1};
    sol.numberOfWeeks(vec);

    return 0;
}