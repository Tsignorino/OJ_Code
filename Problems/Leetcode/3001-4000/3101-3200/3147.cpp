#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = 0; i < k; ++i) {
            int res = 0;
            for (int j = i + (n - i - 1) / k * k; j >= 0; j -= k) {
                res += energy[j];
                ans = max(ans, res);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}