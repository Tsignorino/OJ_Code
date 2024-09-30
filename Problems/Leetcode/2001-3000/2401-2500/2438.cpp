#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

long long quickPow(long long a, long long b, int p) {
    long long ans = 1;
    a = (a % p + p) % p;

    for (; b; b >>= 1) {
        if (b & 1) {
            ans = a * ans % p;
        }

        a = a * a % p;
    }

    return ans;
}

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> res {1};
        while (n) {
            int lowbit = n & -n;
            res.emplace_back(res.back() * 1ll * lowbit % mod);
            n ^= lowbit;
        }

        vector<int> invs;
        for (int& v : res) {
            invs.emplace_back(quickPow(v, mod - 2, mod));
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.emplace_back(res[r + 1] * 1ll * invs[l] % mod);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> queries {
        {0, 1},
        {2, 2},
        {0, 3}
    };
    sol.productQueries(15, queries);

    return 0;
}