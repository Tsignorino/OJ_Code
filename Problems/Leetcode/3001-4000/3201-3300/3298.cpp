#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        vector<int> c(26);
        for (char ch : word2) {
            c[ch - 'a']++;
        }

        int less = 0;
        for (int v : c) {
            if (v > 0) {
                less++;
            }
        }

        ll ans = 0;
        int l = 0;
        for (char ch : word1) {
            if (--c[ch - 'a'] == 0) {
                less--;
            }

            while (less == 0) {
                char out = word1[l++];
                if (c[out - 'a'] == 0) {
                    less++;
                }
                c[out - 'a']++;
            }

            ans += l;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}