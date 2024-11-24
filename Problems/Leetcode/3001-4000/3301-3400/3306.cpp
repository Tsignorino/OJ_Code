#include <bits/stdc++.h>

#include "debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();

        string vowels("aeiou");

        auto f = [&](int k) {
            ll res = 0;
            map<char, int> mp;
            int cnt = 0;
            for (int l = 0, r = 0; r < n; ++r) {
                if (vowels.contains(word[r])) {
                    mp[word[r]]++;
                } else {
                    cnt++;
                }

                for (; mp.size() == 5 && cnt >= k; ++l) {
                    char ch = word[l];
                    if (vowels.contains(word[l])) {
                        if (--mp[word[l]] == 0) {
                            mp.erase(word[l]);
                        }
                    } else {
                        cnt--;
                    }
                }
                res += l;
            }
            return res;
        };

        return f(k) - f(k + 1);
    }
};

int main() {
    Solution sol;

    return 0;
}
