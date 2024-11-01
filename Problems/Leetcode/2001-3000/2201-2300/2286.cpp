#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class BookMyShow {
    using ll = long long;

private:
    int n, m;
    vector<ll> mn;
    vector<ll> sum;

private:
    void update(int i, ll val, int o, int l, int r) {
        if (l == r) {
            mn[o] += val, sum[o] += val;
            return;
        }

        int m = l + (r - l) / 2;
        if (i <= m) {
            update(i, val, o << 1, l, m);
        } else {
            update(i, val, o << 1 | 1, m + 1, r);
        }
        mn[o] = min(mn[o << 1], mn[o << 1 | 1]);
        sum[o] = sum[o << 1] + sum[o << 1 | 1];
    }

    ll query(int L, int R, int o, int l, int r) {
        if (L <= l && r <= R) {
            return sum[o];
        }

        ll res = 0;
        int m = l + (r - l) / 2;
        if (L <= m) {
            res += query(L, R, o << 1, l, m);
        }
        if (R > m) {
            res += query(L, R, o << 1 | 1, m + 1, r);
        }
        return res;
    }

    int findLeft(int R, ll val, int o, int l, int r) {
        if (mn[o] > val) {
            return -1;
        }
        if (l == r) {
            return l;
        }

        int m = l + (r - l) / 2;
        if (mn[o << 1] <= val) {
            return findLeft(R, val, o << 1, l, m);
        }
        if (R > m) {
            return findLeft(R, val, o << 1 | 1, m + 1, r);
        }
        return -1;
    }

public:
    BookMyShow(int n, int m) : n(n), m(m), mn(4 << __lg(n)), sum(4 << __lg(n)) {}

    vector<int> gather(int k, int maxRow) { // 找到第一个能倒入 k 升水的桶
        int r = findLeft(maxRow, m - k, 1, 0, n - 1);
        if (r == -1) {
            return {};
        }

        int c = query(r, r, 1, 0, n - 1);
        update(r, k, 1, 0, n - 1);
        return {r, c};
    }

    bool scatter(int k, int maxRow) {
        ll s = query(0, maxRow, 1, 0, n - 1);
        if (s > m * 1ll * (maxRow + 1) - k) {
            return false;
        }

        int i = findLeft(maxRow, m - 1, 1, 0, n - 1);
        while (k) {
            ll diff = min(m - query(i, i, 1, 0, n - 1), k * 1ll);
            update(i, diff, 1, 0, n - 1);
            k -= diff;
            i++;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
