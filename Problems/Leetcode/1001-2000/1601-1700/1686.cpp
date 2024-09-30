#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        //* 贪心 + 绑定排序
        // Alice 选择石头 i，获得 aliceValues[i] 的收益，让 Bob 损失了 bobValues[i] 的收益
        // 相当于 Alice 获得了 aliceValues[i] + bobValues[i] 的收益
        int n = aliceValues.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);

        sort(idxs.begin(), idxs.end(), [&](const int i, const int j) { return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j]; });

        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // Alice
                diff += aliceValues[idxs[i]];
            } else {
                diff -= bobValues[idxs[i]];
            }
        }

        return diff > 0 ? 1 : diff == 0 ? 0 : -1;
    }
};

int main() {
    Solution sol;

    vector<int> aliceValues {1, 2}, bobValues {3, 1};
    cout << sol.stoneGameVI(aliceValues, bobValues);

    return 0;
}