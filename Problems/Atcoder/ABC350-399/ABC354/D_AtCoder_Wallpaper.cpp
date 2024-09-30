#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> res, ret;
    int aa = (a % 4 + 4) % 4;
    if (aa == 0) {
        res = {0, 2, 3, 3};
        ret = {0, 1, 3, 4};
    } else if (aa == 1) {
        res = {0, 1, 1, 2};
        ret = {0, 2, 3, 3};
    } else if (aa == 2) {
        res = {0, 0, 1, 3};
        ret = {0, 1, 1, 2};
    } else {
        res = {0, 1, 3, 4};
        ret = {0, 0, 1, 3};
    }
    ll v = (c - a) / 4 * 4;
    ll s1 = v + res[(c - a) % 4];
    ll s2 = v + ret[(c - a) % 4];

    int h = d - b;
    ll area = (s1 + s2) * (h / 2);
    if (h & 1) {
        if ((b % 2 + 2) % 2 == 0) {
            area += s1;
        } else {
            area += s2;
        }
    }

    cout << area << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
