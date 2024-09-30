#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int _numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector vec(n + 1, vector<pair<int, int>>(m + 1));

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vec[i + 1][j + 1].first = vec[i + 1][j].first + vec[i][j + 1].first - vec[i][j].first;
                vec[i + 1][j + 1].second = vec[i + 1][j].second + vec[i][j + 1].second - vec[i][j].second;

                auto& p = vec[i + 1][j + 1];
                if (grid[i][j] == 'X') {
                    p.first++;
                }
                if (grid[i][j] == 'Y') {
                    p.second++;
                }

                if (p.first == p.second && p.first > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }

    // update:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        vector<array<int, 2>> col_cnt(grid[0].size());
        for (auto& row : grid) {
            int s0 = 0, s1 = 0;
            for (int j = 0; j < row.size(); j++) {
                if (row[j] != '.') {
                    col_cnt[j][row[j] & 1]++;
                }
                s0 += col_cnt[j][0];
                s1 += col_cnt[j][1];
                if (s0 && s0 == s1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}