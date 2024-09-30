#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    双向链表
*/
void solve() {
    int n;
    cin >> n;

    struct Node {
        int l, r;
        int tag;
    };

    vector<Node> vec(n + 1, {-1, -1, 0});
    vec[0] = {1, 1, 1}, vec[1] = {0, 0, 0};

    auto add = [&](int x, int k, int d) {
        if (d == 0) {
            vec[vec[k].l].r = x;
            vec[x].l = vec[k].l;
            vec[x].r = k;
            vec[k].l = x;
        } else {
            vec[x].r = vec[k].r;
            vec[vec[k].r].l = x;
            vec[k].r = x;
            vec[x].l = k;
        }
    };

    for (int i = 2; i <= n; ++i) {
        int k, d;
        cin >> k >> d;

        add(i, k, d);
    }

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        vec[x].tag = 1;
    }

    for (int i = vec[0].r; i; i = vec[i].r) {
        if (vec[i].tag == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
