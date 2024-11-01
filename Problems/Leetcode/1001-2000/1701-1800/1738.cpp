#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> vec;
        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre[i + 1][j + 1] = pre[i + 1][j] ^ pre[i][j + 1] ^ pre[i][j] ^ matrix[i][j];
                vec.emplace_back(pre[i + 1][j + 1]);
            }
        }

        ranges::nth_element(vec, vec.end() - k);
        return vec[vec.size() - k];
    }
};

int main() {
    Solution sol;

    return 0;
}