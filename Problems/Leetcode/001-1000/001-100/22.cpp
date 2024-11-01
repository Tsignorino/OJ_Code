#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s(n * 2, ' ');

        // 选或不选：记录左括号的个数
        // 左括号个数不能超过3，右括号的个数不能超过左括号
        function<void(int, int)> func = [&](int i, int cnt) -> void {
            if (i == n * 2) {
                ans.emplace_back(s);
                return;
            }

            if (cnt < n) {
                s[i] = '(';
                func(i + 1, cnt + 1);
            }
            if (i - cnt < cnt) {
                s[i] = ')';
                func(i + 1, cnt);
            }
        };

        func(0, 0);

        return ans;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<int> vec;

        //* diff 左括号个数减去右括号个数
        function<void(int, int)> func = [&](int i, int diff) -> void {
            if (vec.size() == n) {
                string s(n * 2, ')');
                for (const int& v : vec) {
                    s[v] = '(';
                }
                ans.emplace_back(s);
                return;
            }

            for (int j = 0; j <= diff; ++j) {
                vec.emplace_back(i + j);
                func(i + j + 1, diff - j + 1);
                vec.pop_back();
            }
        };

        func(0, 0);
        return ans;
    }
};