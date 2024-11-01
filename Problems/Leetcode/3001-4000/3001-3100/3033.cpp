#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix);
        
        int n = ans[0].size();
        for (int j = 0; j < n; ++j) {
            int maxV = 0;
            for (vector<int>& row : ans) {
                maxV = max(maxV, row[j]);
            }

            for (vector<int>& row : ans) {
                if (row[j] == -1) {
                    row[j] = maxV;
                }
            }
        }

        return ans;
    }
};