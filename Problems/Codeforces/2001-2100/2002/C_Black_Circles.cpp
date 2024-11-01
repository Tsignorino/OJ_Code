#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

const double PI = acos(-1);

template <typename T = ll>
struct Point {
    T x, y;
    Point(const T& x_ = 0, const T& y_ = 0) : x(x_), y(y_) {}

    template <typename U = ll>
    operator Point<U>() {
        return Point<U>(U(x), U(y));
    }

    Point operator-() const { return Point(-x, -y); }
    int operator^(const Point& a) { return x * a.y - y * a.x; }

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

template <typename T = ll>
long long dis_2d_Square(T x1, T y1, T x2, T y2) { // 平面距离的平方
    return (x1 - x2) * 1ll * (x1 - x2) + (y1 - y2) * 1ll * (y1 - y2);
}
template <typename T = ll>
long long dis_2d_Square(Point<T>& p1, Point<T>& p2) { // 平面距离的平方
    return (p1.x - p2.x) * 1ll * (p1.x - p2.x) + (p1.y - p2.y) * 1ll * (p1.y - p2.y);
}

double toArc(double x) { // 角度转弧度
    return PI / 180 * x;
}

void solve() {
    int n;
    cin >> n;
    vector<Point<int>> vec(n);
    for (auto& p : vec) {
        cin >> p;
    }

    Point<int> s, t;
    cin >> s >> t;

    ll d = dis_2d_Square(s, t);
    for (auto& p : vec) {
        if (dis_2d_Square(p, t) <= d) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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