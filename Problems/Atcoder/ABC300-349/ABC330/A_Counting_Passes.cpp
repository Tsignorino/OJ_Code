#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, l;
    cin >> n >> l;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        cnt += (val >= l);
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}