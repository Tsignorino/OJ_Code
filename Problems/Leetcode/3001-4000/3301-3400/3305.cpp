#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        string t("aeiou");

        auto check = [&](string&& s) {
            vector<int> vis(5);
            int cnt = 0;
            for (char ch : s) {
                if (t.contains(ch)) {
                    vis[t.find(ch)] = 1;
                } else {
                    cnt++;
                }
            }
            return cnt == k && accumulate(vis.begin(), vis.end(), 0) == 5;
        };

        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int len = 1; len <= n - i; ++len) {
                if (check(word.substr(i, len))) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    sol.countOfSubstrings("iqeaouqi", 2); // 3

    return 0;
}