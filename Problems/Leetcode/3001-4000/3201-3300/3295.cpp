#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> S(bannedWords.begin(), bannedWords.end());

        int cnt = 0;
        for (string& s : message) {
            if (S.contains(s)) {
                cnt++;
            }
        }
        return cnt >= 2;
    }
};

int main() {
    Solution sol;

    return 0;
}