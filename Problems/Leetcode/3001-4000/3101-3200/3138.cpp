#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
 * 不是只拼接一次，且操作是连接（不能用 GCD）
 *
 * 2024.5.5 数据太弱  hack数据：aabb（实际输出：2，预期输出：4）
 */

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int cnt[26] {};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // 检查子串的长度是否可能为 len
        auto check = [&](int len) {
            for (int i = 0; i < n; i += len) {
                int tmp[26] {};
                for (int j = 0; j < len; j++) {
                    tmp[s[i + j] - 'a']++;
                }
                for (int j = 0; j < 26; j++) {
                    if (tmp[j] * (n / len) != cnt[j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        for (int i = 1; i <= n; i++) {
            if (n % i == 0 && check(i)) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}