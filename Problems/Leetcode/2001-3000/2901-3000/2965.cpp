#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n * n;
        int d1 = -m * (m + 1) / 2;
        long long d2 = (long long) -m * (m + 1) * (m * 2 + 1) / 6;
        for (auto& row : grid) {
            for (int x : row) {
                d1 += x;
                d2 += x * x;
            }
        }
        int d = d2 / d1;
        return {(d + d1) / 2, (d - d1) / 2};
    }
};

int main() {
    Solution sol;

    return 0;
}