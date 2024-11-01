#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();

        deque<int> q;
        long long sum = 0;
        int ans = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            while (!q.empty() && chargeTimes[r] >= chargeTimes[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(r);
            sum += runningCosts[r];

            while (l <= r && sum * (r - l + 1) + chargeTimes[q.front()] > budget) {
                sum -= runningCosts[l++];
                if (q.front() < l) {
                    q.pop_front();
                }
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> chargeTimes {11, 12, 19};
    vector<int> runningCosts {10, 8, 7};
    sol.maximumRobots(chargeTimes, runningCosts, 19);

    return 0;
}