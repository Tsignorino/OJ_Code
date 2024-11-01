#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (int& v : batteryPercentages) {
            if (v > ans) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}