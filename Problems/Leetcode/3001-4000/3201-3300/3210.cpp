#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ans(s);
        for (int i = 0; i < n; ++i) {
            ans[i] = s[(i + k) % n];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}