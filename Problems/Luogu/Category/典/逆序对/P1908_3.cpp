#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    权值线段树求逆序对
*/

/*
    权值线段树基于值域划分，往往需要离散化。

    作用: 求一段区间的某个数字的出现次数;
         查询整体区间的第 k 大/小的值; （注意是`整体区间`，任意区间需要利用`主席树`）

    权值线段树一般 update 即是 build。
*/
class SegTree {
private:
    int n;
    vector<int> cnt;

public:
    SegTree() {}
    SegTree(int n) : n(n), cnt(n << 2) {}
    SegTree(vector<int>& vec) : SegTree(vec.size()) {
        for (int& v : vec) {
            update(1, 1, n, v);
        }
    }

    // 添加一个数字
    void update(int i, int l, int r, int x) {
        if (l == r) {
            cnt[i]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (x <= mid) {
            update(i << 1, l, mid, x);
        }
        if (x > mid) {
            update(i << 1 | 1, mid + 1, r, x);
        }
        cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    }

    // 单点查询：求某数的出现次数
    int query(int i, int l, int r, int x) {
        if (l == r) {
            return cnt[i];
        }
        int mid = l + (r - l) / 2;
        if (x <= mid) {
            return query(i << 1, l, mid, x);
        }
        return query(i << 1 | 1, mid + 1, r, x);
    }

    // 区间查询 [L, R]：查询一段区间中所有数字出现的总次数
    int query(int i, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return cnt[i];
        }
        int ans = 0;
        int mid = l + (r - l) / 2;
        if (L <= mid) {
            ans += query(i << 1, l, mid, L, R);
        }
        if (R > mid) {
            ans += query(i << 1 | 1, mid + 1, r, L, R);
        }
        return ans;
    }

    // 查询整个值域中第 k 小的数
    int Kth_Min(int i, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = l + (r - l) / 2;
        int cl = cnt[i << 1], cr = cnt[i << 1 | 1];
        if (k <= cl) {
            return Kth_Min(i << 1, l, mid, k);
        }
        return Kth_Min(i << 1 | 1, mid + 1, r, k - cl);
    }

    // 查询整个值域中第 k 大的数
    int Kth_Max(int i, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = l + (r - l) / 2;
        int cl = cnt[i << 1], cr = cnt[i << 1 | 1];
        if (k <= cr) {
            return Kth_Max(i << 1, l, mid, k);
        }
        return Kth_Max(i << 1 | 1, mid + 1, r, k - cr);
    }

public:
    void update(int x) { return update(1, 1, n, x); }
    int query(int x) { return query(1, 1, n, x); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    int Kth_Max(int k) { return Kth_Max(1, 1, n, k); }
    int Kth_Min(int k) { return Kth_Min(1, 1, n, k); }
};
// 注意下标从 1 开始。

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> res(vec);
    ranges::sort(res);
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int& v : vec) {
        v = lower_bound(res.begin(), res.end(), v) - res.begin() + 1; // 下标从 1 开始
    }

    SegTree tree(n);

    ll ans = 0;
    for (int& v : vec) {
        tree.update(v);
        ans += tree.query(v + 1, n);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}