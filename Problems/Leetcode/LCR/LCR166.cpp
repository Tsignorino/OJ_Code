#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int n = frame[0].size();
        vector<int> f(n + 1);
        for (vector<int>& row : frame) {
            for (int j = 0; j < n; ++j) {
                f[j + 1] = max(f[j + 1], f[j]) + row[j];
            }
        }
        return f[n];
    }
};