#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        vector<int> cnt(26);
        for (int l = 0, r = 0; r < s.size(); ++r) {
            char ch = s[r] - 'a';
            cnt[ch]++;

            while (cnt[ch] > 2) {
                cnt[s[l++] - 'a']--;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};