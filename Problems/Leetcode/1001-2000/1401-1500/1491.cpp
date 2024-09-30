#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    double average(vector<int>& salary) {
        int sum = reduce(salary.begin(), salary.end());
        auto [mn, mx] = ranges::minmax(salary);
        return (double) (sum - mn - mx) / (salary.size() - 2);

        // return (double) (accumulate(salary.begin(), salary.end(), 0) - ranges::max(salary) - ranges::min(salary)) / (salary.size() - 2);
    }
};

int main() {
    Solution sol;

    return 0;
}