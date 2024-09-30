#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        //* (1) 当找到了一个长度为 L 且替换 k 个字符后全部相等的子串，就无需考虑长度更小的子串了
        //* (2) 当找到了一个长度为 L 且替换 k 个字符后不能全部相等的子串，右边界再移动，子串一定不符合要求
        int n = s.size(), cnt = 0;
        vector<int> vec(26);

        int l = 0, r = 0;
        for (; r < n; ++r) {
            vec[s[r] - 'A']++;
            cnt = max(cnt, vec[s[r] - 'A']); // 出现的最多次数

            // 根据第二条，右边界不能再移动，需要移动左边界
            // 根据第一条，左边界只能移动一次
            if (r - l + 1 - cnt > k) {
                vec[s[l++] - 'A']--;
            }
        }

        return r - l;
    }
};

int main() {
    Solution sol;

    string s("AABABBA");
    int k = 1;
    cout << sol.characterReplacement(s, k);

    return 0;
}