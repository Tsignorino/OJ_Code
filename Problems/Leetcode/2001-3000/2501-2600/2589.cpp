
#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

/*
    1.贪心排序
    2.线段树优化
    3.栈、二分
*/
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int ans = 0;
        vector<int> vec(tasks.back()[1] + 1);
        for (vector<int>& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            d -= reduce(vec.begin() + start, vec.begin() + end + 1);
            for (int i = end; d > 0; --i) {
                if (vec[i]) {
                    continue;
                }
                vec[i] = 1;
                d--;
                ans++;
            }
        }
        return ans;
    }
};

class SegTree {
#define ls(o) o << 1
#define rs(o) o << 1 | 1
public:
    vector<int> cnt, tag;

public:
    SegTree(int n) {
        int m = 2 << (32 - __builtin_clz(n));
        cnt.resize(m);
        tag.resize(m);
    }

    void apply(int o, int l, int r) {
        cnt[o] = r - l + 1;
        tag[o] = 1;
    }

    void push_down(int o, int l, int m, int r) {
        if (tag[o] == 0) {
            return;
        }
        apply(ls(o), l, m);
        apply(rs(o), m + 1, r);
        tag[o] = 0;
    }

    int query(int o, int l, int r, int todoL, int todoR) {
        if (todoR < l || todoL > r) {
            return 0;
        }
        if (todoL <= l && r <= todoR) {
            return cnt[o];
        }

        int mid = l + (r - l) / 2;
        push_down(o, l, mid, r);
        // if (mid >= todoR) {
        //     return query(ls(o), l, mid, todoL, todoR);
        // }
        // if (mid < todoL) {
        //     return query(rs(o), mid + 1, r, todoL, todoR);
        // }
        return query(ls(o), l, mid, todoL, todoR) + query(rs(o), mid + 1, r, todoL, todoR);
    }

    void update(int o, int l, int r, int todoL, int todoR, int& suf) {
        int size = r - l + 1;
        if (cnt[o] == size) {
            return;
        }
        if (todoL <= l && r <= todoR && size - cnt[o] <= suf) {
            suf -= size - cnt[o];
            apply(o, l, r);
            return;
        }

        int mid = l + (r - l) / 2;
        push_down(o, l, mid, r);
        if (mid < todoR) {
            update(rs(o), mid + 1, r, todoL, todoR, suf);
        }
        if (suf) {
            update(ls(o), l, mid, todoL, todoR, suf);
        }
        cnt[o] = cnt[ls(o)] + cnt[rs(o)];
    }
#undef ls
#undef rs
};

class Solution_ {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [](auto& a, auto& b) { return a[1] < b[1]; });

        int u = tasks.back()[1];
        SegTree tree(u);
        for (vector<int>& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            d -= tree.query(1, 1, u, start, end); // 去掉运行中的时间点
            if (d > 0) { // 新增时间点
                tree.update(1, 1, u, start, end, d);
            }
        }
        return tree.cnt[1];
    }
};

class Solution__ {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        ranges::sort(tasks, [](auto& a, auto& b) { return a[1] < b[1]; });
        vector<array<int, 3>> stk {
            {-2, -2, 0}
        };
        for (vector<int>& t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            auto& [_, r, s] = *prev(lower_bound(stk.begin(), stk.end(), start, [](const auto& a, int b) { return a[0] < b; }));
            d -= stk.back()[2] - s;
            if (start <= r) {
                d -= r - start + 1;
            }
            if (d <= 0) {
                continue;
            }
            while (end - stk.back()[1] <= d) {
                auto& [l, r, _] = stk.back();
                d += r - l + 1;
                stk.pop_back();
            }
            stk.push_back({end - d + 1, end, stk.back()[2] + d});
        }
        return stk.back()[2];
    }
};

int main() {
    Solution sol;

    return 0;
}
