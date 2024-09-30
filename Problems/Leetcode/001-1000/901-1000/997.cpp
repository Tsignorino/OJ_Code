#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n), out(n);
        for (auto& vec : trust) {
            int u = vec[0], v = vec[1];
            u--, v--;
            out[u]++, in[v]++;
        }

        for (int i = 0; i < n; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}