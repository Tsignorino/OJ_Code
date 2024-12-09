#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        const int N = 100;
        vector<vector<int>> g(N + 1);
        for (auto& p : points) {
            int x = p[0], y = p[1];
            g[x].emplace_back(y);
        }
        for (auto& v : g) {
            ranges::sort(v);
        }

        int ans = -1;
        for (int x1 = 0; x1 <= N; ++x1) {
            for (int x2 = 0; x2 <= N; ++x2) {
                if (x1 == x2) {
                    continue;
                }
                for (int i = 0; i < (int) g[x1].size() - 1; ++i) {
                    for (int j = 0; j < (int) g[x2].size() - 1; ++j) {
                        if (g[x1][i] == g[x2][j] && g[x1][i + 1] == g[x2][j + 1]) {
                            int ok = 1;
                            for (int k = x1 + 1; k < x2; ++k) {
                                for (int& v : g[k]) {
                                    if (v >= g[x1][i] && v <= g[x1][i + 1]) {
                                        ok = 0;
                                        break;
                                    }
                                }
                                if (ok == 0) {
                                    break;
                                }
                            }
                            if (ok) {
                                ans = max(ans, (g[x1][i + 1] - g[x1][i]) * (x2 - x1));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
