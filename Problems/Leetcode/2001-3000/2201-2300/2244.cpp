#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> ump;
        for (int& v : tasks) {
            ump[v]++;
        }

        int ans = 0;
        for (auto& [v, cnt] : ump) {
            if (cnt == 1) {
                return -1;
            }
            ans += (cnt + 2) / 3;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}