#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int m = (sqrt(8.0 * candies + 1) - 1) / 2;
        int k = m / n, extra = m % n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = k * (k - 1) / 2 * n + k * (i + 1) + (i < extra ? k * n + i + 1 : 0);
        }
        ans[extra] += candies - m * (m + 1) / 2;
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}