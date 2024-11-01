#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;

        // 第 i 台机器制作 m 份金属的花费
        auto check = [&](int i, int m) {
            long long total = 0;
            for (int j = 0; j < n; ++j) {
                long long require = 1LL * m * composition[i][j] - stock[j];
                if (require > 0) { // 存货不够
                    total += require * cost[j];
                }
            }
            return total;
        };

        // <= target  <==>  >=(target + 1) << 1
        for (int i = 0; i < k; ++i) {
            int l = -1, r = 1e9 + 7;
            while (l + 1 < r) { // (l, r)
                int mid = l + (r - l) / 2;

                if (check(i, mid) < budget + 1) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            ans = max(ans, l);
        }

        return ans;
    }
};
int main() {
    Solution sol;

    int n = 3; // 金属种类  n = composition[0].size();
    int k = 2; // 机器数    k = composition.size();
    int budget = 15; // 预算

    // 第 i 台机器，制作一份合金 需要 j 种金属的数量
    vector<vector<int>> composition = {
        {1, 1, 1 },
        {1, 1, 10}
    };

    vector<int> stock = {0, 0, 0}; // 金属存货
    vector<int> cost = {1, 2, 3}; // 购置金属的花费

    cout << sol.maxNumberOfAlloys(n, k, budget, composition, stock, cost);

    return 0;
}