#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestSubstring(string s, int k) {
        //* 滑窗
        int res = 0, n = s.size();

        // unordered_set<int> set;
        // for (const char& c : s) {
        //     set.emplace(c - 'a');
        // }
        // int SIZE = set.size();
        int SIZE = 26;

        // t 表示给定的字符数量，介于 [1, 26] 或者 [1, SIZE]
        for (int t = 1; t <= SIZE; ++t) {
            vector<int> cnt(26);
            int total = 0; // 窗口内字符种类数量
            int less = 0; // 计数器，表示出现次数小于 k 的字符的数量（减少遍历 cnt 数组的开销）
            for (int l = 0, r = 0; r < n; ++r) {
                cnt[s[r] - 'a']++;

                if (cnt[s[r] - 'a'] == 1) {
                    less++, total++;
                }
                if (cnt[s[r] - 'a'] == k) {
                    less--;
                }

                while (total > t) {
                    cnt[s[l] - 'a']--;

                    if (cnt[s[l] - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s[l] - 'a'] == 0) {
                        less--, total--;
                    }

                    l++;
                }

                if (less == 0) {
                    res = max(res, r - l + 1);
                }
            }
        }

        return res;

        //* 分治
        // function<int(const string&, int, int, int)> f = [&](const string& s, int l, int r, int k) {
        //     vector<int> cnt(26, 0);
        //     for (int i = l; i <= r; ++i) {
        //         cnt[s[i] - 'a']++;
        //     }

        //     char c = 0; // 分割字符
        //     for (int i = 0; i < 26; ++i) {
        //         if (cnt[i] > 0 && cnt[i] < k) {
        //             c = i + 'a';
        //             break;
        //         }
        //     }

        //     if (c == 0) {
        //         return r - l + 1;
        //     }

        //     int i = l, res = 0;
        //     while (i <= r) {
        //         while (i <= r && s[i] == c) {
        //             i++;
        //         }
        //         if (i > r) {
        //             break;
        //         }

        //         int begin = i;
        //         while (i <= r && s[i] != c) { // 走到下一个分割字符
        //             i++;
        //         }

        //         res = max(res, f(s, begin, i - 1, k));
        //     }

        //     return res;
        // };

        // return f(s, 0, s.size() - 1, k);
    }
};

int main() {
    Solution sol;

    string s("aaabb");
    int k = 3;
    cout << sol.longestSubstring(s, k);

    return 0;
}