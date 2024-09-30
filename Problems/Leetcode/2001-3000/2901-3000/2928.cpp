#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int distributeCandies(int n, int limit) {
        // 容斥
        auto c2 = [&](int x) {
            return x > 1 ? x * (x - 1) / 2 : 0;
        };

        return c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1);
    }
};

int main() {
    Solution sol;

    return 0;
}