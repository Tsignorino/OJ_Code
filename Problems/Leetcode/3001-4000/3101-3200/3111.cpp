#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        ranges::sort(points, [](const auto& a, const auto& b) { return a[0] < b[0]; });
        int ans = 0;
        int r = -1;
        for (auto& p : points) {
            if (p[0] > r) {
                ans++;
                r = p[0] + w;
            }
        }
        return ans;
    }
};

class mySolution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> set;
        for (vector<int>& p : points) {
            set.insert(p[0]);
        }

        int cnt = 0;
        while (!set.empty()) {
            int v = *set.begin();
            while (!set.empty() && *set.begin() <= v + w) {
                set.erase(set.begin());
            }
            cnt++;
        }
        return cnt;
    }
};