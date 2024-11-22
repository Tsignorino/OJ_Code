#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll sum = 0LL;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        sum += num;
    }

    ll s = sqrt(sum);
    if (s * s == sum) {
        puts("YES");
    } else {
        puts("NO");
    }
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
