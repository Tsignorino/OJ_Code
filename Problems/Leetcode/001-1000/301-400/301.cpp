#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
public:
    vector<string> removeInvalidParentheses(string s) {
        // 哈希去重
        unordered_map<string, int> ump;

        // 统计原字符串 maxV
        int l = 0, r = 0;
        for (const char& ch : s) {
            if (ch == '(') {
                l++;
            } else if (ch == ')') {
                r++;
            }
        }
        int maxV = min(l, r);

        // score 左括号 +1，右括号 -1
        int len = 0;
        function<void(int, int, string)> f = [&](int pos, int score, string res) -> void {
            if (score < 0 || score > maxV) {
                return;
            }

            if (pos == s.size()) {
                if (score == 0 && res.size() >= len) {
                    // 确保获得最长字符串
                    if (res.size() > len) {
                        ump.clear();
                    }
                    len = res.size();
                    ump[res]++;
                }
                return;
            }

            char ch = s[pos++];
            if (ch == '(') {
                f(pos, score + 1, res + ch);
                f(pos, score, res);
            } else if (ch == ')') {
                f(pos, score - 1, res + ch);
                f(pos, score, res);
            } else {
                f(pos, score, res + ch);
            }
        };

        f(0, 0, "");

        // 记录答案
        vector<string> ans;
        for (const auto& [str, _] : ump) {
            ans.emplace_back(str);
        }
        return ans;
    }
};

class Solution_1 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        // 判断字符串是否有效
        function<bool(string)> f = [&](string t) -> bool {
            int cnt = 0;
            for (const char& ch : t) {
                if (ch == '(') {
                    cnt++;
                } else if (ch == ')') {
                    cnt--;
                    if (cnt < 0) {
                        return false;
                    }
                }
            }
            return cnt == 0;
        };

        unordered_set<string> curSet;
        curSet.insert(s);
        while (true) {
            for (const string& str : curSet) {
                if (f(str)) {
                    ans.emplace_back(str);
                }
            }

            // 保证删除的数量最少
            if (ans.size() > 0) {
                return ans;
            }

            unordered_set<string> nextSet;
            for (const string& str : curSet) {
                for (int i = 0; i < str.size(); ++i) {
                    if (i > 0 && str[i] == str[i - 1]) {
                        continue;
                    }

                    // 加入删除当前字符的结果
                    if (str[i] == '(' || str[i] == ')') {
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, s.size()));
                    }
                }
            }

            curSet = nextSet;
        }
    }
};