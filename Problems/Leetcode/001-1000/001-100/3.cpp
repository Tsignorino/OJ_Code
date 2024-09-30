#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), pre = -1, ans = 0;
        unordered_map<int, int> cnt; // [c, idx]
        for (int i = 0; i < n; ++i) {
            if (cnt.find(s[i]) != cnt.end()) {
                pre = max(pre, cnt.find(s[i])->second);
            }

            cnt[s[i]] = i;
            ans = max(ans, i - pre);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s("pwwkew");
    cout << sol.lengthOfLongestSubstring(s);

    return 0;
}