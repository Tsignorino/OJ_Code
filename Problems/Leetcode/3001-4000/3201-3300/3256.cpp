#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        vector<pair<int, int>> p(3);
        ranges::fill(p, pair(INT_MIN, -1));

        auto update = [&](vector<int>& row) {
            for (int j = 0; j < row.size(); j++) {
                int x = row[j];
                if (x > p[0].first) {
                    if (p[0].second != j) {
                        if (p[1].second != j) {
                            p[2] = p[1];
                        }
                        p[1] = p[0];
                    }
                    p[0] = {x, j};
                } else if (j != p[0].second && x > p[1].first) {
                    if (p[1].second != j) {
                        p[2] = p[1];
                    }
                    p[1] = {x, j};
                } else if (j != p[0].second && j != p[1].second && x > p[2].first) {
                    p[2] = {x, j};
                }
            }
        };

        int m = board.size();
        vector<vector<pair<int, int>>> suf(m);
        for (int i = m - 1; i > 1; i--) {
            update(board[i]);
            suf[i] = p;
        }

        long long ans = LLONG_MIN;
        ranges::fill(p, pair(INT_MIN, -1));
        for (int i = 1; i < m - 1; i++) {
            update(board[i - 1]);
            for (int j = 0; j < board[i].size(); j++) {
                for (auto& [x, j1] : p) {
                    for (auto& [y, j2] : suf[i + 1]) {
                        if (j1 != j && j2 != j && j1 != j2) {
                            ans = max(ans, (long long) x + board[i][j] + y);
                            break;
                        }
                    }
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