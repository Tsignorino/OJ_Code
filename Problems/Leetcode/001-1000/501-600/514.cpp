#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int clac(int len, int a, int b) { return min((len + a - b) % len, (len + b - a) % len); }

    int findRotateSteps(string ring, string key) {
        int n = key.size(), m = ring.size();
        vector<int> pos[26];
        for (int i = 0; i < m; i++) {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector dp(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (const int& j : pos[key[i] - 'a']) {
                if (i == 0) {
                    dp[i][j] = min(dp[i][j], 0 + clac(m, 0, j) + 1);
                    continue;
                }

                for (const int& k : pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + clac(m, k, j) + 1);
                }
            }
        }

        return *ranges::min_element(dp.back());
    }
};

int main() {
    Solution sol;

    string ring("godding"), key("gd");
    cout << sol.findRotateSteps(ring, key);

    return 0;
}