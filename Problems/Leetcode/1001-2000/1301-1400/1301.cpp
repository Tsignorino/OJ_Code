#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    using PII = pair<int, int>;

    vector<int> pathsWithMaxScore(vector<string>& g) {
        int n = g.size();
        vector f(n, vector<PII>(n, {-1, 0}));
        f[n - 1][n - 1] = {0, 1};

        auto update = [&](int i, int j, int x, int y) {
            if (x >= n || y >= n || f[x][y].first == -1) {
                return;
            }

            if (f[i][j].first < f[x][y].first) {
                f[i][j] = f[x][y];
            } else if (f[i][j].first == f[x][y].first) {
                f[i][j].second += f[x][y].second;
                f[i][j].second %= MOD;
            }
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == n - 1 && j == n - 1 || g[i][j] == 'X') {
                    continue;
                }

                update(i, j, i + 1, j);
                update(i, j, i, j + 1);
                update(i, j, i + 1, j + 1);

                if (f[i][j].first != -1) {
                    f[i][j].first += (g[i][j] == 'E' ? 0 : g[i][j] - '0');
                }
            }
        }
        return f[0][0].first == -1 ? vector<int> {0, 0} : vector<int> {f[0][0].first, f[0][0].second};
    }
};

int main() {
    Solution sol;

    return 0;
}