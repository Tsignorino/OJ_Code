#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int accountBalanceAfterPurchase(int num) {
        // return 100 - (num / 10 + (num % 10 >= 5)) * 10;
        return 100 - (num + 5) / 10 * 10;
    }
};

int main() {
    Solution sol;

    return 0;
}