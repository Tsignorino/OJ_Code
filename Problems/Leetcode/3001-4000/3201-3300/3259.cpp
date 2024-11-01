#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector f(n + 1, vector<long long>(2));
        for (int i = 0; i < n; ++i) {
            f[i + 1][0] = max(f[i][0] + a[i], f[i][1]);
            f[i + 1][1] = max(f[i][1] + b[i], f[i][0]);
        }
        return ranges::max(f[n]);
    }
};

int main() {
    Solution sol;

    return 0;
}