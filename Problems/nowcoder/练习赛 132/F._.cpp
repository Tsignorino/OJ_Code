// Date: 2024-11-30  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 源自：https://ac.nowcoder.com/acm/contest/view-submission?submissionId=73750308

struct RT {
    int a, b, c;
};
vector<RT> vec;

auto init = []() {
    const int M = 2100010;
    for (int m = 2; m * m <= M; m++) {
        for (int n = 1; n < m; n++) {
            if (__gcd(m, n) != 1 || (m - n) % 2 == 0) {
                continue;
            }
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            if (c > M) {
                continue;
            }
            for (int k = 1; k * c <= M; k++) {
                int ta = k * a;
                int tb = k * b;
                int tc = k * c;
                if (ta > tb) {
                    swap(ta, tb);
                }
                vec.emplace_back(ta, tb, tc);
            }
        }
    }
    return 0;
}();

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int res = INT_MAX;
    int ok = 0;
    for (auto& t : vec) {
        if (t.a * t.a + t.b * t.b == t.c * t.c || t.a * t.a + t.c * t.c == t.b * t.b || t.b * t.b + t.c * t.c == t.a * t.a) {
            ok = 1;

            res = min(res, abs(t.a - a) + abs(t.b - b) + abs(t.c - c));
            res = min(res, abs(t.a - a) + abs(t.c - b) + abs(t.b - c));
            res = min(res, abs(t.b - a) + abs(t.a - b) + abs(t.c - c));
            res = min(res, abs(t.b - a) + abs(t.c - b) + abs(t.a - c));
            res = min(res, abs(t.c - a) + abs(t.a - b) + abs(t.b - c));
            res = min(res, abs(t.c - a) + abs(t.b - b) + abs(t.a - c));
        }
    }

    if (ok && res != INT_MAX) {
        cout << res << "\n";
    } else {
        cout << "-1\n";
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