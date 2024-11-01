#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector vec(n, vector<int>(11));
        for (auto& v : pick) {
            vec[v[0]][v[1]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int ok = 0;
            for (int j = 0; j < 11; ++j) {
                if (vec[i][j] > i) {
                    ok = 1;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}