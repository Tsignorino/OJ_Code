#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    vector<int> res(vec);
    ranges::sort(res);
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int& v : vec) {
        v = ranges::lower_bound(res, v) - res.begin();
    }

    int m = res.size() + 1;
    vector<int> tree(m * 4);
    auto update = [&](auto&& self, int o, int l, int r, int val) {
        if (l == r) {
            tree[o]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (val <= mid) {
            self(self, o << 1, l, mid, val);
        } else {
            self(self, o << 1 | 1, mid + 1, r, val);
        }
        tree[o] = tree[o << 1] + tree[o << 1 | 1];
    };
    auto query = [&](auto&& self, int o, int l, int r, int k) {
        if (l == r) {
            return res[l];
        }
        int mid = l + (r - l) / 2;
        if (k <= tree[o << 1]) {
            return self(self, o << 1, l, mid, k);
        }
        return self(self, o << 1 | 1, mid + 1, r, k - tree[o << 1]);
    };

    for (int i = 1, k = 1; i <= n; i += 2, ++k) {
        if (i > 1) {
            update(update, 1, 1, m, vec[i - 1]);
        }
        update(update, 1, 1, m, vec[i]);
        cout << query(query, 1, 1, m, k) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
