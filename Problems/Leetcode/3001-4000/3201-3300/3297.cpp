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

        vector<int> C(26);

        auto check = [&]() {
            int ok = 1;
            for (int i = 0; i < 26; ++i) {
                if (C[i] < c[i]) {
                    ok = 0;
                    break;
                }
            }
            return ok;
        };

        ll ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            C[word1[r] - 'a']++;
            if (check()) {
                ans += n - r;
                while (check()) {
                    C[word1[l++] - 'a']--;
                    if (check()) {
                        ans += n - r;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    /*
        "dcbdcdccb"
        "cdd"
    */
    /*
        "ddccdddccdddccccdddccdcdcd"
        "ddc"
    */
    sol.validSubstringCount("ddccdddccdddccccdddccdcdcd", "ddc");

    return 0;
}