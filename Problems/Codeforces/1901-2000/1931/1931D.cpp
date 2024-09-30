#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

/*

    (a[i] + a[j]) % x == 0  ==>  (a[i] % x + a[j] % x) % x == 0
                            ==>  a[i] % x + a[j] % x == x or 0
                            ==>  a[i] % x == (x - a[j] % x) % x

    (a[i] - a[j]) % y == 0  ==>  (a[i] % y - a[j] % y) % y == 0
                            ==>  a[i] % y - a[j] % y == 0
                            ==>  a[i] % y == a[j] % y

*/

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    ll cnt = 0;
    map<pair<int, int>, int> ump;

    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;

        int v1 = num % x, v2 = num % y;
        cnt += ump[make_pair(v1, v2)];

        ump[make_pair((x - v1) % x, v2)]++;
    }

    cout << cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
