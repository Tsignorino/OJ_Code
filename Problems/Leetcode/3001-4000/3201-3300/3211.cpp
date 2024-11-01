#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            if (((i >> 1) & i) == 0) {
                ans.push_back(bitset<18>(i ^ mask).to_string().substr(18 - n));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}