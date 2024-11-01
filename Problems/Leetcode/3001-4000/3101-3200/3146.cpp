#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();
        vector<int> vec(26);
        for (int i = 0; i < n; ++i) {
            vec[s[i] - 'a'] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(i - vec[t[i] - 'a']);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}