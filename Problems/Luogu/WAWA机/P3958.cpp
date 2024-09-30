#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct P {
    int x, y, z;
};

__int128 square(int x) {
    return __int128(x) * x;
}
__int128 dis(P& p1, P& p2) {
    return square(p1.x - p2.x) + square(p1.y - p2.y) + square(p1.z - p2.z);
}

void solve() {
    int n, h, r;
    cin >> n >> h >> r;
    vector<P> vec(n);
    vector<int> pa(n), up(n), down(n);
    iota(pa.begin(), pa.end(), 0);
    for (int i = 0; i < n; ++i) {
        auto& v = vec[i];
        cin >> v.x >> v.y >> v.z;
        up[i] = v.z + r;
        down[i] = v.z - r;
    }

    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };

    function<void(int, int)> merge = [&](int x, int y) -> void {
        int px = pa[x], py = pa[y];
        if (px == py) {
            return;
        }

        pa[px] = py;
        up[py] = max(up[px], up[py]);
        down[py] = min(down[px], down[py]);
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) { //! 注意不要漏连
            if (i != j && dis(vec[i], vec[j]) <= square(r * 2)) {
                merge(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (up[i] >= h && down[i] <= 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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
