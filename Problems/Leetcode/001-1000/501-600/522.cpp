#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();

        auto check = [&](string& s, string& t) -> bool {
            int i = 0;
            for (char ch : t) {
                if (s[i] == ch && ++i == s.size()) {
                    return true;
                }
            }
            return false;
        };

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int len = strs[i].size();
            if (len <= ans) { // ! 不能直接将 strs[i].size() 跟 -1 比较大小，-1 会转为无符号整数，是一个很大的正数
                continue;
            }

            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (j != i && check(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = len;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> strs {"aba", "cdc", "eae"};
    sol.findLUSlength(strs);

    return 0;
}