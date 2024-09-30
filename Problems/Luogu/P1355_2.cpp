#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct Point {
    int x, y;
    Point() {}
    Point(int a, int b) : x(a), y(b) {}
    Point operator+(const Point& a) const { return Point(x + a.x, y + a.y); }
    Point operator-(const Point& a) const { return Point(x - a.x, y - a.y); }
    int operator^(const Point& a) { return x * a.y - y * a.x; }
};

void solve() {
    vector<Point> vec(3);
    char ch;
    for (int i = 0; i < 3; ++i) {
        cin >> ch >> vec[i].x >> ch >> vec[i].y >> ch;
    }
    Point o;
    cin >> ch >> o.x >> ch >> o.y >> ch;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 3; ++i) {
        int mid = (o - vec[i]) ^ (o - vec[(i + 1) % 3]);
        cnt1 += mid > 0;
        cnt2 += mid < 0;
    }

    if (cnt1 == 3 || cnt2 == 3) {
        cout << 1 << "\n";
    } else if (cnt1 && cnt2) {
        cout << 2 << "\n";
    } else if (cnt1 + cnt2 == 1) {
        cout << 4 << "\n";
    } else {
        cout << 3 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
