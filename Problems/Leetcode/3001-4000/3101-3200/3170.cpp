#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string clearStars(string s) {
        vector<int> st[26];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                st[s[i] - 'a'].push_back(i);
                continue;
            }
            for (auto& p : st) {
                if (!p.empty()) {
                    p.pop_back();
                    break;
                }
            }
        }

        vector<int> idx;
        for (auto& p : st) {
            idx.insert(idx.end(), p.begin(), p.end());
        }
        ranges::sort(idx);

        string t;
        for (int& v : idx) {
            t.push_back(s[v]);
        }
        return t;
    }
};

int main() {
    Solution sol;

    return 0;
}