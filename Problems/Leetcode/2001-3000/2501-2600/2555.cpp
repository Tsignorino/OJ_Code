#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maximizeWin(vector<int>& res, int k) {
        int n = res.size();
        if (k * 2 + 1 >= res.back() - res.front()) {
            return n;
        }

        int ans = 0, l = 0;
        vector<int> preMax(n + 1);
        for (int r = 0; r < n; ++r) {
            while (res[r] - res[l] > k) {
                l++;
            }
            ans = max(ans, preMax[l] + r - l + 1);
            preMax[r + 1] = max(preMax[r], r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}