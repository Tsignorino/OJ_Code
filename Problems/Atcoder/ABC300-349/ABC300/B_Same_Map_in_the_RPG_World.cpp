#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H, string(W, ' '));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    vector<string> B(H, string(W, ' '));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            bool ok = true;
            for (int k = 0; k < H; ++k) {
                for (int l = 0; l < W; ++l) {
                    if (A[k][l] != B[(i + k) % H][(j + l) % W]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}