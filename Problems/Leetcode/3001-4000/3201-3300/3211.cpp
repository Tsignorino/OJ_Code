#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int x = mask ^ i;
            if (((x >> 1) & x) == 0) {
                ans.push_back(bitset<18>(i).to_string().substr(18 - n));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}