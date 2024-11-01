#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        for (int i = 0; i < bottomLeft.size(); ++i) {
            vector<int>& p1 = bottomLeft[i];
            vector<int>& q1 = topRight[i];
            for (int j = i + 1; j < topRight.size(); ++j) {
                vector<int>& p2 = bottomLeft[j];
                vector<int>& q2 = topRight[j];

                int x1 = max(p1[0], p2[0]), x2 = min(q1[0], q2[0]);
                int y1 = max(p1[1], p2[1]), y2 = min(q1[1], q2[1]);

                int a = min(x2 - x1, y2 - y1);
                if (a > 0) {
                    ans = max(ans, a * 1LL * a);
                }
            }
        }
        return ans;
    }
};