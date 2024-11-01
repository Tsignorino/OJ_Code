#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for (char& ch : s) {
            if (isalpha(ch)) {
                ans.push_back(ch);
            } else {
                ans.pop_back();
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s("cb34");
    sol.clearDigits(s);

    return 0;
}