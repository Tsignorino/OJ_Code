#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int ans = 1, cnt = 0;
        for (int l = 0, r = 1; r < n; ++r) {
            if (s[r] == s[r - 1] && ++cnt > 1) {
                l++;
                while (s[l] != s[l - 1]) {
                    l++;
                }

                cnt = 1;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s("52233");
    cout << sol.longestSemiRepetitiveSubstring(s);

    return 0;
}