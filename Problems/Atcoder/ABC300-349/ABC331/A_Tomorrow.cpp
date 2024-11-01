#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int M, D;
    cin >> M >> D;

    int y, m, d;
    cin >> y >> m >> d;

    d++;
    if (d > D) {
        d -= D;
        m++;
    }
    if (m > M) {
        m -= M;
        y++;
    }
    printf("%d %d %d", y, m, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}