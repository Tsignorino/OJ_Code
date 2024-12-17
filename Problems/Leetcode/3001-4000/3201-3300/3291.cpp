#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> zfunc(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i, r = i + z[i]++;
        }
    }
    return z;
}

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        vector<int> maxJump(n);
        for (auto& s : words) {
            auto z = zfunc(s + '#' + target);
            int m = s.size();
            for (int i = 0; i < n; ++i) {
                maxJump[i] = max(maxJump[i], z[m + 1 + i]);
            }
        }

        int ans = 0;
        int cur = 0, nxt = 0;
        for (int i = 0; i < n; ++i) {
            nxt = max(nxt, i + maxJump[i]);
            if (i == cur) {
                if (i == nxt) {
                    return -1;
                }
                cur = nxt;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}