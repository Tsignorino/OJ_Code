#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = ranges::max(nums);

        vector<ll> cnt(m + 1);
        for (int& v : nums) {
            cnt[v]++;
        }

        vector<ll> g(m + 1);
        for (int i = m; i > 0; --i) {
            ll res = 0;
            for (int j = i; j <= m; j += i) {
                res += cnt[j];
                g[i] -= g[j];
            }
            g[i] += res * (res - 1) / 2;
        }

        vector<ll> pre(m + 2);
        for (int i = 0; i < m + 1; ++i) {
            pre[i + 1] = pre[i] + g[i];
        }

        vector<int> ans;
        for (ll& q : queries) {
            ans.emplace_back(ranges::upper_bound(pre, q) - pre.begin() - 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}