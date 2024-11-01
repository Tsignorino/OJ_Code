#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
    vector<int> t;

    void update(int o, int l, int r, int i, int val) {
        if (l == r) {
            t[o] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (i <= mid) {
            update(o << 1, l, mid, i, val);
        } else {
            update(o << 1 | 1, mid + 1, r, i, val);
        }

        // 将区域的长度保存在右端点
        t[o] = max(t[o << 1], t[o << 1 | 1]);
    }

    int query(int o, int l, int r, int x) {
        if (r <= x) {
            return t[o];
        }
        int mid = l + (r - l) / 2;
        if (x <= mid) {
            return query(o << 1, l, mid, x);
        }
        return max(t[o << 1], query(o << 1 | 1, mid + 1, r, x));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;
        for (auto& q : queries) {
            mx = max(mx, q[1]);
        }
        mx++;

        set<int> s {0, mx};
        t.resize(2 << (32 - __builtin_clz(mx)));

        vector<bool> ans;
        for (auto& q : queries) {
            int x = q[1];
            auto iter = s.lower_bound(x);
            int pre = *prev(iter);
            int nxt = *iter;
            if (q[0] == 1) {
                s.insert(x);
                update(1, 0, mx, x, x - pre);
                update(1, 0, mx, nxt, nxt - x);
            } else {
                // [0, pre] or [pre, x]
                ans.emplace_back(max(query(1, 0, mx, pre), x - pre) >= q[2]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}