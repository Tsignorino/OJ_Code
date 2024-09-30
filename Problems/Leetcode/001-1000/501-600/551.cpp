#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    bool checkRecord(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s.substr(i, 3) == "LLL") {
                return false;
            }
        }
        return count(s.begin(), s.end(), 'A') < 2;
    }
};

int main() {
    Solution sol;

    return 0;
}