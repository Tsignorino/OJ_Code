#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Define mapping relationship
unordered_map<int, string> ump {
    {0, ""    },
    {1, ""    },
    {2, "abc" },
    {3, "def" },
    {4, "ghi" },
    {5, "jkl" },
    {6, "mno" },
    {7, "pqrs"},
    {8, "tuv" },
    {9, "wxyz"}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) {
            return {};
        }

        vector<string> ans;
        string s(n, ' '); // Record enumeration result
        function<void(int)> f = [&](int i) -> void {
            // Boundary condition
            if (i == n) {
                ans.emplace_back(s);
                return;
            }

            for (const char& ch : ump[digits[i] - '0']) {
                s[i] = ch;
                f(i + 1);
            }
        };

        f(0);

        return ans;
    }
};