#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                ans += i - j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}