#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int N = 9;

void solve() {
    vector g(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> g[i][j];
        }
    }

    // row
    for (int i = 0; i < N; ++i) {
        int row = 0;
        for (int j = 0; j < N; ++j) {
            row |= 1 << (g[i][j] - 1);
        }
        if (row != 0b1'1111'1111) {
            cout << "No\n";
            return;
        }
    }

    // col
    for (int j = 0; j < N; ++j) {
        int col = 0;
        for (int i = 0; i < N; ++i) {
            col |= 1 << (g[i][j] - 1);
        }
        if (col != 0b1'1111'1111) {
            cout << "No\n";
            return;
        }
    }

    // zone
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            int zone = 0;
            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    zone |= 1 << (g[i + a][j + b] - 1);
                }
            }
            if (zone != 0b1'1111'1111) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}