#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (auto& s : commands) {
            if (s == "RIGHT") {
                y++;
            } else if (s == "DOWN") {
                x++;
            } else if (s == "UP") {
                x--;
            } else {
                y--;
            }
        }
        return x * n + y;
    }
};

int main() {
    Solution sol;

    return 0;
}