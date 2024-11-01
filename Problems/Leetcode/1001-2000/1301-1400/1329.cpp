#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> vec(min(m, n));
        for (int k = 1 - n; k < m; ++k) {
            int l = max(k, 0), r = min(k + n, m);
            for (int i = l; i < r; ++i) {
                vec[i - l] = mat[i][i - k];
            }

            sort(vec.begin(), vec.begin() + r - l);

            for (int i = l; i < r; ++i) {
                mat[i][i - k] = vec[i - l];
            }
        }
        return mat;
    }
};

int main() {
    Solution sol;

    return 0;
}