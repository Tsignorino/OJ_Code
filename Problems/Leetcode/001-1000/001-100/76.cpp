#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<int, int> ump;
        for (const char& c : t) {
            ump[c]++;
        }

        int l = 0, r = 0, cnt = m, minLen = 1e9;
        int left = n; // 记录子串左端点
        while (r < n) {
            if (ump.find(s[r]) != ump.end() && --ump[s[r]] >= 0) {
                cnt--;
            }

            while (cnt == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    left = l;
                }

                if (ump.find(s[l]) != ump.end() && ++ump[s[l]] > 0) {
                    cnt++;
                }
                l++;
            }

            r++;
        }

        return left == n ? "" : s.substr(left, minLen);
    }
};

int main() {
    Solution sol;

    string s("ADOBECODEBANC"), t("ABC");
    cout << sol.minWindow(s, t);

    return 0;
}