#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char ch1 = pattern[0], ch2 = pattern[1];
        int c1 = 0, c2 = 0;
        ll ans = 0;
        for (char ch : text) {
            if (ch == ch2) {
                ans += c1;
                c2++;
            }
            if (ch == ch1) {
                c1++;
            }
        }
        return ans + max(c1, c2);
    }
};

int main() {
    Solution sol;

    sol.maximumSubsequenceCount("abdcdbc", "ac");

    return 0;
}