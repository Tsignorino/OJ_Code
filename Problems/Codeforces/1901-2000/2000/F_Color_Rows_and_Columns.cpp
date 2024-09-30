#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> f(k + 1, INT_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }

        for (int j = k; j >= 0; --j) {
            for (int v = 1; v <= a + b && v + j <= k; ++v) { // score
                int x = 0, y = 0; // 空白部分
                if (v <= b - a) {
                    x = a, y = b - v;
                } else { // x + y = a + b - v
                    x = (a + b - v) / 2, y = a + b - v - x;
                }
                f[j + v] = min(f[j + v], f[j] + a * b - x * y);
            }
        }
    }
    cout << (f[k] == INT_MAX / 2 ? -1 : f[k]) << "\n";
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