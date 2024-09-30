#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            f[i] += f[j];
        }
        f[i] += 1; // 以本身结尾
    }
    cout << f[n] << "\n";

    // vector<int> memo(n + 1, -1);
    // function<int(int)> f = [&](int x) -> int {
    //     if (x == 1) {
    //         return 1;
    //     }

    //     int& res = memo[x];
    //     if (res != -1) {
    //         return res;
    //     }

    //     int sum = 0;
    //     for (int i = 1; i <= x / 2; ++i) {
    //         sum += f(i);
    //     }
    //     return res = sum + 1;
    // };

    // cout << f(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
