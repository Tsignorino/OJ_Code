#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});

        int ans = 0, dis = startFuel;
        priority_queue<int> fuel;
        for (auto& s : stations) {
            while (!fuel.empty() && dis < s[0]) {
                dis += fuel.top();
                fuel.pop();
                ans++;
            }
            if (dis < s[0]) {
                return -1;
            }
            fuel.emplace(s[1]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}