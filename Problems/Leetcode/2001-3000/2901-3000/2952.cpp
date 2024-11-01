#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        ranges::sort(coins);
        int ans = 0, s = 1, i = 0; // 最开始，[0, s-1]
        while (s <= target) {
            if (i < coins.size() && coins[i] <= s) {
                s += coins[i++];
            } else {
                s *= 2;
                ans++;
            }
        }
        return ans;
    }
};