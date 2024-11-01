#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        auto check = [&](int i, int j) {
            int cnt[2] {};
            cnt[grid[i][j] & 1]++;
            cnt[grid[i][j + 1] & 1]++;
            cnt[grid[i + 1][j] & 1]++;
            cnt[grid[i + 1][j + 1] & 1]++;
            return cnt[0] >= 3 || cnt[1] >= 3;
        };
        return check(0, 0) || check(0, 1) || check(1, 0) || check(1, 1);
    }
};

class Solution_2 {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                char ch = grid[i][j];
                if ((grid[i][j + 1] == ch) + (grid[i + 1][j] == ch) + (grid[i + 1][j + 1] == ch) != 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

class mySolution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                char ch = grid[i][j];
                if ((grid[i][j + 1] == ch) + (grid[i + 1][j] == ch) + (grid[i + 1][j + 1] == ch) >= 2 ||
                    (grid[i][j + 1] != ch) + (grid[i + 1][j] != ch) + (grid[i + 1][j + 1] != ch) == 3) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // [["B","W","B"],["W","W","B"],["B","B","B"]]  true

    return 0;
}