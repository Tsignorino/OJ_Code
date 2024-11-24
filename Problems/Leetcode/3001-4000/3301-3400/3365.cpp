#include <bits/stdc++.h>

#include "debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        map<string, int> mp;
        int len = s.size() / k;
        for (int i = 0; i < k; ++i) {
            mp[s.substr(i * len, len)]++;
            mp[t.substr(i * len, len)]--;
        }
        for (auto& [_, v] : mp) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}