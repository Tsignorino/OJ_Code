#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxProfitAssignment_(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = {difficulty[i], profit[i]};
        }
        ranges::sort(vec);

        // vector<int> preMax(n + 1);
        // for (int i = 0; i < n; ++i) {
        //     preMax[i + 1] = max(preMax[i], vec[i].second);
        // }
        // ranges::sort(difficulty);
        // int ans = 0;
        // for (int& w : worker) {
        //     int id = ranges::upper_bound(difficulty, w) - difficulty.begin();
        //     ans += preMax[id];
        // }
        ranges::sort(worker);
        int ans = 0, j = 0, max_profit = 0;
        for (int w : worker) {
            while (j < n && vec[j].first <= w) {
                max_profit = max(max_profit, vec[j++].second);
            }
            ans += max_profit;
        }
        return ans;
    }

public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        ranges::sort(id, [&](const int i, const int j) { return difficulty[i] < difficulty[j]; });

        vector<int> preMax(n + 1);
        for (int i = 0; i < n; ++i) {
            preMax[i + 1] = max(preMax[i], profit[id[i]]);
        }

        ranges::sort(difficulty);
        int ans = 0;
        for (int& w : worker) {
            int id = ranges::upper_bound(difficulty, w) - difficulty.begin();
            ans += preMax[id];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> difficulty {5, 50, 92, 21, 24, 70, 17, 63, 30, 53};
    vector<int> profit {68, 100, 3, 99, 56, 43, 26, 93, 55, 25};
    vector<int> worker {96, 3, 55, 30, 11, 58, 68, 36, 26, 1};
    sol.maxProfitAssignment(difficulty, profit, worker);

    return 0;
}