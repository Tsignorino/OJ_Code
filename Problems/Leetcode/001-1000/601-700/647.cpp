#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size() * 2 + 1; // 处理后的字符数组长度
        char t[n]; // 处理后的字符数组

        //* process
        for (int i = 0, j = 0; i < n; ++i) {
            t[i] = (i & 1) == 0 ? '#' : s[j++];
        }

        int res[n]; // 记录扩散中心能构建的回文串的回文半径
        int ans = 0;
        for (int i = 0, center = 0, r = 0, length; i < n; ++i) {
            length = r > i ? min(res[2 * center - i], r - i) : 1;

            //* Brute Force
            while (i + length < n && i - length >= 0 && t[i + length] == t[i - length]) {
                length++;
            }

            //* update
            if (i + length > r) {
                r = i + length, center = i;
            }
            ans += length / 2;

            //* record
            res[i] = length;
        }

        return ans;
    }
};