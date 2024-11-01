#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            map<char, int> mp;
            for (int j = i; j < n; ++j) {
                if (++mp[s[j]] >= k) {
                    ans += n - j;
                    break;
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