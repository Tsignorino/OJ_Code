#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x;
    cin >> n >> x;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (v <= x) {
            sum += v;
        }
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}