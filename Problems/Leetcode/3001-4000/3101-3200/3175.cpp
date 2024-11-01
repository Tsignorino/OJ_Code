#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int mxId = 0, win = 0;
        for (int i = 1; i < skills.size() && win < k; ++i) {
            if (skills[i] > skills[mxId]) {
                mxId = i;
                win = 0;
            }
            win++;
        }
        return mxId;
    }
};

int main() {
    Solution sol;

    return 0;
}