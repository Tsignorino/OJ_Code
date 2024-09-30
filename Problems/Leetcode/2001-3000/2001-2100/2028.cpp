#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = reduce(rolls.begin(), rolls.end());
        int tot = mean * (n + rolls.size());
        int diff = tot - sum;
        if (diff < n || diff > n * 6) {
            return {};
        }

        int avg = diff / n, cnt = diff % n;
        vector<int> ans(cnt, avg + 1);
        ans.insert(ans.end(), n - cnt, avg);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> rolls({3, 2, 4, 3});
    int mean = 4, n = 2;
    sol.missingRolls(rolls, mean, n);

    return 0;
}