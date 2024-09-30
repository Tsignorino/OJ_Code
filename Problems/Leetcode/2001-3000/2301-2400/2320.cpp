#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9 + 7;
constexpr int MX = 1e4 + 1;
int f[MX] {1, 2};
int init = []() {
    for (int i = 2; i < MX; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    return 0;
}();

class Solution {
public:
    int countHousePlacements(int n) { return f[n] * 1ll * f[n] % mod; }
};