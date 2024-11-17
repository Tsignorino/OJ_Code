#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr ll inf = 9e18;

template <class Info, class Tag>
class SegTree {
private:
    int n;
    vector<Info> tree;
    vector<Tag> tag;

    void apply(int o, const Tag& t) { tag[o].apply(t), tree[o].apply(t); }
    void push(int o) { apply(o << 1, tag[o]), apply(o << 1 | 1, tag[o]), tag[o] = Tag(); }
    void pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

public:
    SegTree() : n(0) {}
    SegTree(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
    template <class T>
    SegTree(vector<T>& init_) {
        init(init_);
    }

    template <class T>
    void init(const vector<T>& init_) {
        n = init_.size();
        tree.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());

        function<void(int, int, int)> build = [&](int o, int l, int r) -> void {
            if (l == r) {
                tree[o] = init_[l];
                return;
            }
            int m = l + (r - l) / 2;
            build(o << 1, l, m);
            build(o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(1, 0, n - 1);
    }

public:
    void modify(int id, const Info& v, int o, int l, int r) {
        if (l == r) {
            tree[o] = v;
            return;
        }
        push(o);
        int m = l + (r - l) / 2;
        if (id <= m) {
            modify(id, v, o << 1, l, m);
        } else {
            modify(id, v, o << 1 | 1, m + 1, r);
        }
        pull(o);
    }
    void modify(int id, const Info& v) { modify(id, v, 1, 0, n - 1); }

    void modify(int L, int R, const Tag& t, int o, int l, int r) {
        if (L <= l && r <= R) {
            apply(o, t);
            return;
        }
        push(o);
        int m = l + (r - l) / 2;
        if (L <= m) {
            modify(L, R, t, o << 1, l, m);
        }
        if (m < R) {
            modify(L, R, t, o << 1 | 1, m + 1, r);
        }
        pull(o);
    }
    void modify(int L, int R, const Tag& t) { modify(L, R, t, 1, 0, n - 1); }

    Info query(int id, int o, int l, int r) {
        if (l == r) {
            return tree[o];
        }
        push(o);
        int m = l + (r - l) / 2;
        if (id <= m) {
            return query(id, o << 1, l, m);
        }
        return query(id, o << 1 | 1, m + 1, r);
    }
    Info query(int id) { return query(id, 1, 0, n - 1); }

    Info query(int L, int R, int o, int l, int r) {
        if (L <= l && r <= R) {
            return tree[o];
        }
        push(o);
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(L, R, o << 1, l, m);
        }
        if (m < L) {
            return query(L, R, o << 1 | 1, m + 1, r);
        }
        return query(L, R, o << 1, l, m) + query(L, R, o << 1 | 1, m + 1, r);
    }
    Info query(int L, int R) { return query(L, R, 1, 0, n - 1); }

    Info queryAll() { return tree[1]; }
};

struct Tag {
    ll add = 0;
    void apply(const Tag& t) { add += t.add; }
};

struct Info {
    ll mx = 0;
    void apply(const Tag& t) { mx += t.add; }
};
Info operator+(const Info& a, const Info& b) {
    return Info(max(a.mx, b.mx));
}

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<Info> init(n);
        for (int i = 0; i < n; ++i) {
            init[i].mx = nums[i];
        }

        SegTree<Info, Tag> t(init);
        if (t.queryAll().mx <= 0) {
            return 0;
        }
        for (int i = 0; i < queries.size(); ++i) {
            auto& q = queries[i];
            t.modify(q[0], q[1], Tag(-q[2]));
            if (t.queryAll().mx <= 0) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums {10};
    vector<vector<int>> queries {
        {0, 0, 5},
        {0, 0, 3},
        {0, 0, 2}
    };
    cout << sol.minZeroArray(nums, queries);

    return 0;
}