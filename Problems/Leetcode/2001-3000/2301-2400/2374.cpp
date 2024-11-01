#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        int ans = 0;
        vector<ll> vec(n);
        for (int i = 0; i < n; ++i) {
            int to = edges[i];
            vec[to] += i;
            if (vec[to] > vec[ans] || vec[to] == vec[ans] && to < ans) {
                ans = to;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}