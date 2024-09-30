#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    操作后的数组一定还是只含 -1,0,1
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    // f[i][j] 表示 第 i 个位置在前面的数保证不下降时变成 j-1 的最少操作次数
    vector f(n + 1, vector<ll>(3, LLONG_MAX / 2));
    f[1][vec[1] + 1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (vec[i] == -1) {
            f[i][0] = f[i - 1][0]; // -1 -> -1

            if (vec[i - 1] == 1) { // -1 -> 0
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
            }

            if (vec[i - 1] == 1) { // -1 -> 1
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 2;
            } else {
                f[i][2] = f[i - 1][2] + 2;
            }
        }

        if (vec[i] == 0) {
            f[i][0] = f[i - 1][0] + 1; // 0 -> -1

            f[i][1] = min(f[i - 1][0], f[i - 1][1]); // 0 -> 0

            if (vec[i - 1] == 1) { // 0 -> 1
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
            } else {
                f[i][2] = f[i - 1][2] + 1;
            }
        }

        if (vec[i] == 1) {
            f[i][0] = f[i - 1][0] + 2; // 1 -> -1

            if (vec[i - 1] == -1) { // 1 -> 0
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
            } else {
                f[i][1] = f[i - 1][0] + 1;
            }

            f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])); // 1 -> 1
        }
    }

    ll val = ranges::min(f[n]);
    if (val >= LLONG_MAX / 2) {
        cout << "BRAK\n";
        return;
    }
    cout << val << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}