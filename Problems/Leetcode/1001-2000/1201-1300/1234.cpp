#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), m = n / 4;

        //* 在待替换子串之外的任意字符出现次数不超过 m，才能通过替换使满足条件
        unordered_map<char, int> ump;
        for (const char& c : s) {
            ump[c]++;
        }

        if (ump['Q'] == m && ump['W'] == m && ump['E'] == m && ump['R'] == m) {
            return 0;
        }

        int ans = n;
        for (int l = 0, r = 0; r < n; ++r) {
            ump[s[r]]--;

            while (ump['Q'] <= m && ump['W'] <= m && ump['E'] <= m && ump['R'] <= m) {
                ans = min(ans, r - l + 1);

                ump[s[l]]++;
                l++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s("QWER");
    cout << sol.balancedString(s);

    return 0;
}