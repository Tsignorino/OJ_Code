#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> ok(n + 1);
        ok[0] = 1;

        for (int i = 0; i < n; ++i) {
            for (string& t : wordDict) {
                if (ok[i] && s.substr(i, t.size()) == t) {
                    ok[i + t.size()] = 1;
                }
            }
        }

        // set<string> S(wordDict.begin(), wordDict.end());
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (ok[j] && S.contains(s.substr(j, i - j))) {
        //             ok[i] = 1;
        //             break;
        //         }
        //     }
        // }

        return ok[n];
    }
};

int main() {
    Solution sol;

    return 0;
}