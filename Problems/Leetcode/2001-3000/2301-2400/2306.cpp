#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    long long distinctNames(vector<string>& ideas) {
        array<set<string>, 26> groups;
        for (auto& s : ideas) {
            groups[s[0] - 'a'].emplace(s.substr(1));
        }

        ll ans = 0;
        for (int i = 1; i < 26; ++i) {
            for (int j = 0; j < i; ++j) {
                int m = 0;
                for (auto& s : groups[i]) {
                    if (groups[j].contains(s)) {
                        m++;
                    }
                }
                ans += (groups[i].size() - m) * 1ll * (groups[j].size() - m);
            }
        }
        return ans * 2;
    }
};

int main() {
    Solution sol;

    return 0;
}