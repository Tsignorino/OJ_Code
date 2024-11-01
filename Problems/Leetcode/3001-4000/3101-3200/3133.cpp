#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long ans = x;
        int j = 0;
        for (long long t = ~x, lb; n >> j; t ^= lb) {
            lb = t & -t;
            ans |= (long long) (n >> j++ & 1) * lb;
        }

        return ans;
    }
};

class Solution_2 {
public:
    long long minEnd(int n, int x) {
        n--;

        long long ans = x;
        int i = 0, j = 0;
        while (n >> j) {
            if ((ans >> i & 1) == 0) {
                ans |= (n * 1ll >> j & 1) << i;
                j++;
            }
            i++;
        }
        return ans;
    }
};

class mySolution {
public:
    long long minEnd(int n, int x) {
        n--;

        long long ans = x;
        int cnt = 0, cnt0 = 0;
        while (x) {
            if ((x & 1) == 0) {
                ans |= (n & 1) << cnt;
                cnt0++;
                n >>= 1;
            }
            x >>= 1;
            cnt++;
        }

        long long pre = n;
        ans |= pre << (32 - __builtin_clz(ans));
        return ans;
    }
};

int main() {
    Solution sol;
    // sol.minEnd(3, 4);
    // sol.minEnd(2, 7);
    sol.minEnd(2, 5);

    return 0;
}