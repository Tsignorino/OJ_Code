#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
    const int mod = 1e9 + 7;

public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> cnt(26); // 以某个字符结尾的子序列的数量
        int tot = 1; // 计算空串
        for (char ch : s) {
            int add = (tot - cnt[ch - 'a'] + mod) % mod;
            tot = (tot + add) % mod;
            cnt[ch - 'a'] = (cnt[ch - 'a'] + add) % mod;
        }
        return (tot - 1 + mod) % mod; // 除去空串
    }
};

int main() {
    Solution sol;

    return 0;
}