#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

int calc(int x, int y) {
    int cnt = 1;

    while (true) {
        if (x >= cnt) {
            x -= cnt++;
        } else {
            break;
        }
        if (y >= cnt) {
            y -= cnt++;
        } else {
            break;
        }
    }
    return cnt - 1;
}

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) { return max(calc(red, blue), calc(blue, red)); }
};

int main() {
    Solution sol;

    return 0;
}