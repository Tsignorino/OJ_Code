#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();

        vector<int> preSum(n + 1);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + (possible[i] ? 1 : -1);
        }

        for (int i = 1; i < n; ++i) { // !
            if (preSum[i] * 2 > preSum[n]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> vec {1, 1, 1, 1, 1};

    Solution sol;
    cout << sol.minimumLevels(vec);

    return 0;
}