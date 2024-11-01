#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int N = 102;
        vector<int> d(N);
        for (auto& v : nums) {
            d[v[0]]++;
            d[v[1] + 1]--;
        }

        vector<int> pre(N + 1);
        for (int i = 0; i < N; ++i) {
            pre[i + 1] = pre[i] + d[i];
        }

        int ans = 0;
        for (int i = 1; i <= 100; ++i) {
            if (pre[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}