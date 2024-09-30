#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string removeTrailingZeros(string s) {
        // s.erase(s.begin() + 1 + s.find_last_not_of('0'), s.end());
        // return s;
        return s.substr(0, s.find_last_not_of('0') + 1);
    }
};

int main() {
    Solution sol;

    return 0;
}