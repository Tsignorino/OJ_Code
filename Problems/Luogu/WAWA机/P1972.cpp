#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

class Fenwick {
    vector<int> f;
    int Op(int a, int b) { return a + b; } // add, max

public:
    explicit Fenwick(int n) : f(n + 1, 0) {}
    explicit Fenwick(vector<int>& vec) : f(vec.size() + 1) {
        for (int i = 0; i < vec.size(); ++i) {
            update(i + 1, vec[i]);
        }
    }

    void update(int id, int val) { // a[i] += val, 1<=i<=n
        for (int i = id; i <= f.size(); i += i & -i) {
            f[i] = Op(f[i], val);
        }
    }

    int preSum(int id) { // [1, id]
        int res = 0;
        for (int i = id; i > 0; i &= i - 1) { // i -= i & -i
            res += f[i];
        }
        return res;
    }

    int rangeSum(int l, int r) { return preSum(r) - preSum(l - 1); } // [l, r]
};

/*
    “对于若干个询问的区间[l,r]，如果他们的r都相等的话，那么项链中出现的同一个数字，一定是只关心出现在最右边的那一个的”
*/

struct Q {
    int l, r, id;
};

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int m;
    cin >> m;
    vector<Q> q(m);
    int k = 0;
    for (auto& [l, r, id] : q) {
        cin >> l >> r;
        id = k++;
    }

    ranges::sort(q, [&](const Q& q1, const Q& q2) { return q1.r < q2.r; });

    Fenwick f(n);
    map<int, int> map;
    vector<int> res(m);
    int last = 0;
    for (auto& [l, r, id] : q) {
        for (int i = last; i < r; ++i) { // ! 查询的时候修改
            if (map.contains(vec[i])) {
                f.update(map[vec[i]] + 1, -1);
            }
            f.update(i + 1, 1);
            map[vec[i]] = i;
        }
        last = r;
        res[id] = f.rangeSum(l, r);
    }
    for (int& v : res) {
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
