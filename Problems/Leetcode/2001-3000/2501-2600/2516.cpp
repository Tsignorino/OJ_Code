#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> cnt(3);

        // 先从右边取字符
        int r = n;
        while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            if (r == 0) {
                return -1;
            }
            r--;
            cnt[s[r] - 'a']++;
        }

        int ans = n - r;
        for (int l = 0; l < n; ++l) {
            cnt[s[l] - 'a']++;
            while (r < n && cnt[s[r] - 'a'] > k) {
                cnt[s[r] - 'a']--;
                r++;
            }

            ans = min(ans, l + 1 + n - r);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s("aabaaaacaabc");
    int k = 2;

    return 0;
}