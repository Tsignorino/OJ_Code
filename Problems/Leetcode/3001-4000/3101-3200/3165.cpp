#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

struct node {
    int f00 = 0, f01 = 0, f10 = 0, f11 = 0;
};

class Solution {
    vector<node> t;

    void push_up(int o) {
        auto &p = t[o << 1], q = t[o << 1 | 1];
        t[o] = {
            max(p.f00 + q.f10, p.f01 + q.f00),
            max(p.f00 + q.f11, p.f01 + q.f01),
            max(p.f10 + q.f10, p.f11 + q.f00),
            max(p.f10 + q.f11, p.f11 + q.f01),
        };
    }

    void build(int o, int l, int r, vector<int>& nums) {
        if (l == r) {
            t[o].f11 = max(nums[l], 0);
            return;
        }
        int mid = l + (r - l) / 2;
        build(o << 1, l, mid, nums);
        build(o << 1 | 1, mid + 1, r, nums);
        push_up(o);
    }

    void update(int o, int l, int r, int i, int val) {
        if (l == r) {
            t[o].f11 = max(val, 0);
            return;
        }
        int mid = l + (r - l) / 2;
        if (i <= mid) {
            update(o << 1, l, mid, i, val);
        } else {
            update(o << 1 | 1, mid + 1, r, i, val);
        }
        push_up(o);
    }

public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        // 线段树
        int n = nums.size();
        t.resize(2 << (32 - __builtin_clz(n)));

        build(1, 0, n - 1, nums);

        long long ans = 0;
        for (auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            ans += t[1].f11;
        }
        return ans % MOD;
    }
};

int main() {
    Solution sol;

    return 0;
}