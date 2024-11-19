#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
static constexpr int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = img[i][j];
                int cnt = 1;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        sum += img[ni][nj];
                        cnt++;
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> img {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    sol.imageSmoother(img);

    return 0;
}