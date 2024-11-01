#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/**
 * 一般情况下，只需要找到两个点右侧的比两个位置都大的最左侧的点
 * 特殊情况：两个人本来就在同一位置；右侧的数本来就更大
 *
 * 1. 离线 + 单调栈二分
 * 2. 离线 + 最小堆
 * 3. 在线 + 线段树二分
 */

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<vector<pair<int, int>>> idx(n); // <h, i>
        vector<int> ans(m);

        for (int i = 0; i < m; ++i) {
            auto [a, b] = ranges::minmax(queries[i]);
            if (a == b || heights[a] < heights[b]) { // 特殊情况
                ans[i] = b;
                continue;
            }
            idx[b].emplace_back(heights[a], i); // 左边的数不小于右边的数
        }

        vector<pair<int, int>> stk; // 模拟单调栈
        stk.emplace_back(INT_MAX, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && stk.rbegin()->first <= heights[i]) { // 左侧还有更高的 h
                stk.pop_back();
            }
            for (auto& v : idx[i]) {
                auto iter = ranges::lower_bound(stk, make_pair(v.first, INT_MAX), greater<pair<int, int>>());
                ans[v.second] = (--iter)->second;
            }
            stk.emplace_back(heights[i], i);
        }

        return ans;
    }
};

class Solution1 {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<vector<pair<int, int>>> l(n);
        vector<int> ans(m, -1);

        for (int i = 0; i < m; ++i) {
            auto [a, b] = ranges::minmax(queries[i]);
            if (a == b || heights[a] < heights[b]) { // 特殊情况
                ans[i] = b;
            } else {
                l[b].emplace_back(heights[a], i); // 离线记录 <h, i>
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            for (auto& p : l[i]) { // 之后再查询
                pq.emplace(p);
            }
        }

        return ans;
    }
};

class Solution2 {
    vector<int> tree;

    void build(int o, int l, int r, vector<int>& heights) {
        if (l == r) {
            tree[o] = heights[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(o << 1, l, mid, heights);
        build(o << 1 | 1, mid + 1, r, heights);
        tree[o] = max(tree[o << 1], tree[o << 1 | 1]);
    }

    int query(int o, int l, int r, int L, int v) { // 查询 [L, n-1] 中第一个大于 v 的下标
        if (tree[o] <= v) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = l + (r - l) / 2;
        if (L <= mid) {
            int pos = query(o << 1, l, mid, L, v);
            if (pos >= 0) {
                return pos;
            }
        }
        return query(o << 1 | 1, mid + 1, r, L, v);
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, heights);
        // 线段树的下标从 0 开始

        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            if (a > b) {
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]) {
                ans.emplace_back(b);
            } else {
                ans.emplace_back(query(1, 0, n - 1, b + 1, heights[a]));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}