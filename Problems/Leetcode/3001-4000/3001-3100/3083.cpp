#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        // bool vis[26][26] {};
        int vis[26] {};
        for (int i = 1; i < s.size(); i++) {
            int x = s[i - 1] - 'a', y = s[i] - 'a';
            // vis[x][y] = true;
            // if (vis[y][x]) {
            //     return true;
            // }

            //* 位运算优化
            vis[x] |= 1 << y;
            if (vis[y] >> x & 1) {
                return true;
            }
        }
        return false;
    }
};
