#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 1; i < grid.size(); ++i) {
            if (grid[i][ans]) {
                ans = i;
            }
        }
        return ans;
    }
};