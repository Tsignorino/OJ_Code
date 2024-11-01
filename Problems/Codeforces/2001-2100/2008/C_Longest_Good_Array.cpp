#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    cin >> a >> b;

    b -= a;

    // 0 1 3 6 10 ...
    // 0 0+1 0+1+2 0+1+2+3 0+1+2+3+4 ...
    // 范围 n*(n+1)/2
    int l = 0, r = 45000;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        if (mid * (mid + 1) / 2 <= b) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << "\n"; // 不要忘了第一项
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}