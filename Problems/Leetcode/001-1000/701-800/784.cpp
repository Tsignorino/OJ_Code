#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    //* 回溯
    vector<string> letterCasePermutation_0(string s) {
        int n = s.length();
        vector<string> ans;
        string t(s);

        function<void(int)> f = [&](int i) -> void {
            if (i == n) {
                ans.emplace_back(t);
                return;
            }

            // 变
            if (!isdigit(s[i])) {
                t[i] = s[i] ^ 32;
                /*
                    if (islower(s[i])) {
                        t[i] = (char) (toupper(s[i]));
                    } else {
                        t[i] = (char) (tolower(s[i]));
                    }
                */

                f(i + 1);
                t[i] = s[i]; // 恢复现场
            }

            // 不变
            f(i + 1);
        };

        f(0);
        return ans;
    }

    vector<string> letterCasePermutation_1(string s) {
        int n = s.length();
        vector<string> ans;

        function<void(int)> f = [&](int i) -> void {
            while (i < n && isdigit(s[i])) {
                i++;
            }
            if (i == n) {
                ans.emplace_back(s);
                return;
            }

            s[i] ^= 32;
            f(i + 1);

            s[i] ^= 32;
            f(i + 1);
        };

        f(0);
        return ans;
    }

    //* BFS
    vector<string> letterCasePermutation_2(string s) {
        // 从左往右遍历字符，队列中存储已遍历字符的字母大小的全排列
        // 当遇到数字字符时，在队列所有字符串后面加上数字字符
        // 当遇到字母字符时，把队列所有字符串分别加上字母对应的小写或大写字符，再放入队列
        vector<string> ans;
        queue<string> q;
        q.emplace("");
        while (!q.empty()) {
            string& cur = q.front();

            if (cur.size() == s.size()) { // 队首字符串已满足要求
                ans.emplace_back(cur);
                q.pop();
            } else {
                int i = cur.size();

                // 如果是字母，把变化后的放进去
                if (isalpha(s[i])) {
                    string next(cur);
                    next.push_back(s[i] ^ 32);
                    q.emplace(next);
                }

                // 把未变化的字符放入序列第一个字符串中
                cur.push_back(s[i]);
            }
        }

        return ans;
    }

    //* 二进制位图
    // 找到字母个数 n，那么对应的排列组合为 2^n 种
    vector<string> letterCasePermutation(string s) {
        int n = s.size();

        // 统计字母个数
        int cnt = 0;
        for (const char& ch : s) {
            if (isalpha(ch)) {
                cnt++;
            }
        }

        vector<string> ans;
        for (int mask = 0; mask < (1 << cnt); ++mask) {
            string t;
            for (int j = 0, k = 0; j < n; ++j) {
                // 每个 bit 为 1 的时候，进行翻转（k 表示偏移量）
                if (isalpha(s[j]) && (mask & (1 << k++))) {
                    t.push_back(s[j] ^ 32);
                } else {
                    t.push_back(s[j]);
                }
            }
            ans.emplace_back(t);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    sol.letterCasePermutation("a1b2");

    return 0;
}