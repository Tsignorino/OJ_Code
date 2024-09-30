#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> xs, ys;
        for (vector<int>& p : points) {
            xs.insert(p[0] + p[1]);
            ys.insert(p[1] - p[0]);
        }

        int ans = INT_MAX;
        for (vector<int>& p : points) {
            int x = p[0] + p[1], y = p[1] - p[0];
            xs.erase(xs.find(x));
            ys.erase(ys.find(y));

            ans = min(ans, max(*xs.rbegin() - *xs.begin(), *ys.rbegin() - *ys.begin()));

            xs.insert(x);
            ys.insert(y);
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> points {
        {3,  10},
        {5,  15},
        {10, 2 },
        {4,  4 }
    };

    Solution sol;
    cout << sol.minimumDistance(points);

    return 0;
}