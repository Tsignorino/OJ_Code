#include <bits/stdc++.h>

#include "debug.h"

using namespace std;

using ll = long long;
ll qpow(ll a, ll b, int p, ll res = 1) {
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = a * res % p;
        }
    }
    return res;
}

class Solution {
    static constexpr int MOD = 1'000'000'007;

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return std::move(nums);
        }

        int n = nums.size();
        int mx = ranges::max(nums);
        vector<pair<ll, int>> h(n);
        for (int i = 0; i < n; ++i) {
            h[i] = {nums[i], i};
        }

        ranges::make_heap(h, greater<>());
        for (; k && h[0].first < mx; --k) {
            ranges::pop_heap(h, greater<>());
            h.back().first *= multiplier;
            ranges::push_heap(h, greater<>());
        }

        ranges::sort(h);

        for (int i = 0; i < n; ++i) {
            auto& [x, j] = h[i];
            nums[j] = x % MOD * qpow(multiplier, k / n + (i < k % n), MOD) % MOD;
        }
        return std::move(nums);
    }
};

int main() {
    Solution sol;

    return 0;
}