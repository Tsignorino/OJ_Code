#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] - s[i - 1] == 1) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}