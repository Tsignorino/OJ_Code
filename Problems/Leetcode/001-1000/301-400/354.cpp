#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& p) {
        int n = p.size();
        ranges::sort(p, [](const auto& v1, const auto& v2) { return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]); });

        vector<int> f;
        for (int i = 0; i < n; ++i) {
            auto iter = ranges::lower_bound(f, p[i][1]);
            if (iter == f.end()) {
                f.emplace_back(p[i][1]);
            } else {
                *iter = p[i][1];
            }
        }

        return f.size();
    }
};