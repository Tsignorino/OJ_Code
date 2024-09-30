#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size() * 2 + 1; // 处理后的字符数组长度
        char ss[n]; // 处理后的字符数组

        //* process
        for (int i = 0, j = 0; i < n; ++i) {
            ss[i] = (i & 1) == 0 ? '#' : s[j++];
        }

        int res[n]; // 记录扩散中心能构建的回文串的回文半径
        function<int(int, int)> find = [&](int l, int k) -> int {
            for (int i = l, center = l, r = l, length; i < n; ++i) {
                length = r > i ? min(res[2 * center - i], r - i) : 1;

                //* Brute Force
                while (i + length < n && i - length >= l && ss[i + length] == ss[i - length]) {
                    if (++length > k) {
                        return i + k + (ss[i + k] == '#' ? 0 : 1);
                    }
                }

                //* update
                if (i + length > r) {
                    r = i + length, center = i;
                }

                //* record
                res[i] = length;
            }

            return -1;
        };

        int ans = 0, next = 0;
        while ((next = find(next, k)) != -1) {
            ans++;
        }

        return ans;
    }
};