#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
};

bool operator<(point a, point b) {
    return a.y < b.y;
}

void solve() {
    int n;
    cin >> n;
    vector<point> a(n);
    for (auto& p : a) {
        cin >> p.x >> p.y;
    }

    ranges::sort(a, [&](point a, point b) { return a.x == b.x ? a.y < b.y : a.x < b.x; });

    multiset<point> s;
    double d = 2e9;
    for (int i = 0, j = 0; i < n; s.insert(a[i++])) {
        while (j < i && a[j].x <= a[i].x - d) {
            s.erase(a[j++]);
        }
        for (auto iter = s.lower_bound(point(a[i].x, a[i].y - d)); iter != s.end() && iter->y < a[i].y + d; iter++) {
            d = min(d, hypot(a[i].x - iter->x, a[i].y - iter->y));
        }
    }
    cout << fixed << setprecision(4) << d << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
