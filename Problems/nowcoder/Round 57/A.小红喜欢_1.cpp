#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88888/A
*/

void solve() {
    for (int i = 0; i < 5; ++i) {
        int val;
        cin >> val;
        if (val == 1) {
            cout << i + 1 << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}