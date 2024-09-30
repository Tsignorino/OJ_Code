#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9 + 7;

class Solution {
    using ll = long long;

public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<ll> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + candiesCount[i];
        }

        // queries: type / day / cnt
        vector<bool> ans;
        for (vector<int>& q : queries) {
            int t = q[0], d = q[1], c = q[2];
            ans.emplace_back(pre[t + 1] > d && pre[t + 1] <= (d + 1) * 1ll * c);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}