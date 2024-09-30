#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct Node {
    int a, b, val;
};

/*
    贪心 + 并查集
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Node> vec(m);
    for (auto& v : vec) {
        cin >> v.a >> v.b >> v.val;
        v.a--, v.b--;
    }

    ranges::sort(vec, [&](const Node& x, const Node& y) { return x.val > y.val; });

    vector<int> pa(n);
    iota(pa.begin(), pa.end(), 0);

    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };
    function<void(int, int)> merge = [&](int x, int y) -> void {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }
        pa[px] = py;
    };

    vector<int> tag(n, -1);
    for (int i = 0; i < m; ++i) {
        int pa = find(vec[i].a), pb = find(vec[i].b);
        if (pa == pb) {
            cout << vec[i].val << "\n";
            return;
        } else {
            int& t1 = tag[vec[i].a];
            if (t1 == -1) {
                t1 = vec[i].b;
            } else {
                merge(t1, vec[i].b);
            }

            int& t2 = tag[vec[i].b];
            if (t2 == -1) {
                t2 = vec[i].a;
            } else {
                merge(t2, vec[i].a);
            }
        }
    }
    cout << 0 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
