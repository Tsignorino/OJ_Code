#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s;
        for (char ch : target) {
            for (char i = 'a'; i <= ch; ++i) {
                ans.emplace_back(s + i);
            }
            s.push_back(ch);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}