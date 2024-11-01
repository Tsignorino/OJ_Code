#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        int n = s.size();

        function<bool(int, int)> check = [&](int l, int r) -> bool {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };

        // start 表示回文子串的开始位置
        function<void(int, int)> f = [&](int i, int start) -> void {
            if (i == n) {
                ans.emplace_back(vec);
                return;
            }

            // 不选
            if (i < n - 1) {
                f(i + 1, start);
            }

            // 选
            if (check(start, i)) {
                vec.emplace_back(s.substr(start, i - start + 1));
                f(i + 1, i + 1);
                vec.pop_back();
            }
        };
        f(0, 0);
        return ans;

        // function<void(int)> f = [&](int i) -> void {
        //     if (i == n) {
        //         ans.emplace_back(vec);
        //         return;
        //     }
        //     // 枚举选哪个
        //     for (int j = i; j < n; ++j) {
        //         if (check(i, j)) {
        //             vec.emplace_back(s.substr(i, j - i + 1));
        //             f(j + 1);
        //             vec.pop_back();
        //         }
        //     }
        // };
        // f(0);
        // return ans;
    }
};