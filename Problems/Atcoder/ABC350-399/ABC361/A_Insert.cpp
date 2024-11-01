#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        cout << val << " ";
        if (i == k - 1) {
            cout << x << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
