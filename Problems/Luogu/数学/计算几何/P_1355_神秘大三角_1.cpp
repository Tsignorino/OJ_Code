#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

template <typename T>
struct Point {
    T x, y;

    Point() = default;
    Point(const T& x_, const T& y_) : x(x_), y(y_) {}

    template <typename U = ll>
    operator Point<U>() const {
        return Point<U>(U(x), U(y));
    }

    Point operator-() const { return Point(-x, -y); }
    T operator^(const Point& a) const { return x * a.y - y * a.x; }

    Point& operator+=(const Point& p) { return x += p.x, y += p.y, *this; }
    Point& operator-=(const Point& p) { return x -= p.x, y -= p.y, *this; }
    Point& operator*=(const T& v) { return x *= v, y *= v, *this; }
    Point& operator/=(const T& v) { return x /= v, y /= v, *this; }

    friend Point operator+(Point a, const Point& b) { return a += b; }
    friend Point operator-(Point a, const Point& b) { return a -= b; }
    friend Point operator*(Point a, const T& b) { return a *= b; }
    friend Point operator*(const T& a, Point b) { return b *= a; }
    friend Point operator/(Point a, const T& b) { return a /= b; }
    friend bool operator==(const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }

    friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};
using point = Point<ll>;

const double PI = numbers::pi; // acos(-1);
double toArc(double x) { // 角度转弧度
    return PI / 180 * x;
}

void solve() {
    vector<point> vec(3);
    char ch;
    for (int i = 0; i < 3; ++i) {
        cin >> ch >> vec[i].x >> ch >> vec[i].y >> ch;
    }
    point o;
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

    solve();

    return 0;
}
