#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct Node {
    int a, c, i;
};

bool cmp(Node& n1, Node& n2) {
    return n1.a < n2.a || n1.a == n2.a && n1.c > n2.c;
}

void solve() {
    int n;
    cin >> n;
    vector<Node> vec(n);
    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        vec[i] = {a, c, i};
    }
    ranges::sort(vec, cmp);

    vector<int> id(n, 1);
    for (int i = n - 1, j = n - 1; i >= 0; i = j--) {
        while (j >= 0 && (vec[j].c > vec[i].c)) {
            id[vec[j].i] = 0;
            j--;
        }
    }

    cout << accumulate(id.begin(), id.end(), 0) << "\n";
    for (int i = 0; i < n; ++i) {
        if (id[i]) {
            cout << i + 1 << " ";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
