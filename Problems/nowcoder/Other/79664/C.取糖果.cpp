#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/79664/C
*/

void solve() {
    int n, m;
    cin >> n >> m;

    const int N = 1001;
    vector<int> v(N);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int y;
            cin >> y;

            v[y]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = ans ^ v[i];
    }
    cout << (ans ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}