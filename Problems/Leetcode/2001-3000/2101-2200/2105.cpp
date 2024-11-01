#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int p = 0, q = n - 1;
        int w1 = capacityA, w2 = capacityB;
        int ans = 0;
        while (p < q) {
            if (w1 < plants[p]) {
                w1 = capacityA;
                ans++;
            }
            w1 -= plants[p++];

            if (w2 < plants[q]) {
                w2 = capacityB;
                ans++;
            }
            w2 -= plants[q--];
        }

        if (p == q && max(w1, w2) < plants[p]) {
            ans++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}