#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    /* manacher */
    string longestPalindrome(string s) {
        int n = s.size() * 2 + 1; // 处理后的字符数组长度
        string t(n, ' '); // 处理后的字符数组
        for (int i = 0, j = 0; i < n; ++i) {
            t[i] = (i & 1) == 0 ? '#' : s[j++];
        }

        vector<int> res(n); // 记录扩散中心能构建的回文串的回文半径
        int maxV = 0, start = -1; // 记录最大回文串长度与起始下标
        for (int i = 0, c = 0, r = 0, l; i < n; ++i) {
            l = r > i ? min(res[2 * c - i], r - i) : 1;
            while (i + l < n && i - l >= 0 && t[i + l] == t[i - l]) {
                l++;
            }
            if (i + l > r) {
                r = i + l, c = i;
            }
            if (l > maxV) {
                maxV = l - 1;
                start = (i + l - 1) / 2 - maxV;
            }
            res[i] = l;
        }

        return s.substr(start, maxV);
    }
};