#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    1. 用 vector STL 水过去
    2. 对顶堆
    3. 权值线段树，二分查找，离散化
       (树状数组)
*/

void solve_1() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        vec.insert(ranges::upper_bound(vec, val), val);
        if (i & 1) {
            cout << vec[(i - 1) / 2] << "\n";
        }
    }
}

void solve_2() {
    int n;
    cin >> n;

    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<>> q2;
    int val;
    cin >> val;
    q1.emplace(val);
    cout << q1.top() << "\n";
    for (int i = 2; i <= n; ++i) {
        int val;
        cin >> val;
        if (val > q1.top()) {
            q2.emplace(val);
        } else {
            q1.emplace(val);
        }

        while (abs((int) (q1.size() - q2.size())) > 1) {
            if (q1.size() > q2.size()) {
                q2.emplace(q1.top());
                q1.pop();
            } else {
                q1.emplace(q2.top());
                q2.pop();
            }
        }

        if (i & 1) {
            cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << "\n";
        }
    }
}

void solve_3() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    // 离散化
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    // solve_1();
    // solve_2();
    solve_3();

    return 0;
}
