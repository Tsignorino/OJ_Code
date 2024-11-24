#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 10;
        int ok = 0;
        while (n >= cnt) {
            n -= cnt--;
            ok ^= 1;
        }
        return ok;
    }
};

int main() {
    Solution sol;

    return 0;
}