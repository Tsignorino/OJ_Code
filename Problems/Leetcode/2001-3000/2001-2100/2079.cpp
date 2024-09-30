#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int ans = n, m = capacity;
        for (int i = 0; i < n; ++i) {
            if (m < plants[i]) {
                m = capacity;
                ans += 2 * i;
            }
            m -= plants[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> plants {2, 2, 3, 3};
    cout << sol.wateringPlants(plants, 5);

    return 0;
}