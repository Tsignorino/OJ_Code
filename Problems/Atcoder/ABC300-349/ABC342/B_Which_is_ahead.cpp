#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        vec[val] = i;
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (vec[a] < vec[b]) {
            cout << a << "\n";
        } else {
            cout << b << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}