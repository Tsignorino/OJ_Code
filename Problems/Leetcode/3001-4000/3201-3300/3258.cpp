#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j <= n; ++j) {
                string tmp = s.substr(i, j);
                if (count(tmp.begin(), tmp.end(), '0') <= k || count(tmp.begin(), tmp.end(), '1') <= k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

public:
    // O(n) 滑窗
    int countKConstraintSubstrings_2(string s, int k) {
        int n = s.size();
        int ans = 0;
        vector<int> cnt(2);
        for (int l = 0, r = 0; r < n; ++r) {
            cnt[s[r] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l++] & 1]--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}