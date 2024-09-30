#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i) {
            vector<int>& p = points[i];
            vec.emplace_back(max(abs(p[0]), abs(p[1])), s[i]);
        }
        ranges::sort(vec);

        set<int> set;
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i, v = vec[j].first;
            while (i < n && vec[i].first == v) {
                if (set.contains(vec[i].second)) {
                    return ans;
                } else {
                    set.insert(vec[i].second);
                    i++;
                }
            }
            ans += i - j;
        }
        return ans;
    }
};

class mySolution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        int l = -1, r = 1e9 + 1;
        int ans = 0;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            bool flag = true;
            int vis = 0;
            for (int i = 0; i < n; ++i) {
                int c = s[i] - 'a';
                auto& v = points[i];
                if (abs(v[0]) <= mid && abs(v[1]) <= mid) {
                    if (vis >> c & 1) {
                        flag = false;
                        break;
                    }
                    vis |= 1 << c;
                }
            }

            if (flag) {
                l = mid;
                ans = __popcount(vis);
            } else {
                r = mid;
            }

            // set<char> set;
            // bool flag = false;
            // for (int i = 0; i < n; ++i) {
            //     auto& v = points[i];
            //     if (abs(v[0]) <= mid && abs(v[1]) <= mid) {
            //         if (set.contains(s[i])) {
            //             flag = true;
            //             break;
            //         } else {
            //             set.insert(s[i]);
            //         }
            //     }
            // }
            // if (flag) {
            //     r = mid;
            // } else {
            //     l = mid;
            //     ans = max(ans, (int) set.size());
            // }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points {
        {2,  2 },
        {-1, -2},
        {-4, 4 },
        {-3, 1 },
        {3,  -3}
    };
    sol.maxPointsInsideSquare(points, "abdca");

    return 0;
}