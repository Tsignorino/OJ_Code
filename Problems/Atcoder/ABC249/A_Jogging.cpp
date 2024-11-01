#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;

    auto func = [&](int a, int b, int c) -> int {
        return (x / (a + c) * a + min(x % (a + c), a)) * b;
    };

    int v1 = (x / (a + c) * a + min(x % (a + c), a)) * b;
    int v2 = (x / (d + f) * d + min(x % (d + f), d)) * e;
    if (v1 > v2) {
        cout << "Takahashi";
    } else if (v1 < v2) {
        cout << "Aoki";
    } else {
        cout << "Draw";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}