#include <bits/stdc++.h>

using namespace std;

set<char> s {'a', 'e', 'i', 'o', 'u'};

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> preSum {0};
        for (string& w : words) {
            preSum.emplace_back(preSum.back() + (s.contains(w.front()) && s.contains(w.back())));
        }

        vector<int> ans;
        for (vector<int>& q : queries) {
            ans.emplace_back(preSum[q[1] + 1] - preSum[q[0]]);
        }
        return ans;
    }
};