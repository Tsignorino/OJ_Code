#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        // check(i, j, k) 从 (i, j) 位置开始匹配 word[k...]
        function<bool(int, int, int)> check = [&](int i, int j, int k) -> bool {
            if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[k]) {
                return false;
            }

            if (k == word.size() - 1) {
                return true;
            }

            board[i][j] = '#';
            bool res = check(i + 1, j, k + 1) || check(i - 1, j, k + 1) || check(i, j + 1, k + 1) || check(i, j - 1, k + 1);
            board[i][j] = word[k];

            return res;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (check(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};