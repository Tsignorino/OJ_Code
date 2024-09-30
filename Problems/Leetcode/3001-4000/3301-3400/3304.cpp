#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __popcount(k - 1);

        // string s("a");
        // while (s.size() < k) {
        //     int n = s.size();
        //     for (int i = 0; i < n; ++i) {
        //         s.push_back(s[i] == 'z' ? 'a' : s[i] + 1);
        //     }
        // }
        // return s[k - 1];
    }
};

int main() {
    Solution sol;

    return 0;
}