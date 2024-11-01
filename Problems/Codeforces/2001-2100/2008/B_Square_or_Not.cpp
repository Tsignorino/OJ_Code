#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int x = sqrt(n);
    if (x * x != n) {
        cout << "No\n";

        string s;
        cin >> s;
        return;
    }

    vector vec(x, vector<char>(x));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> vec[i][j];
        }
    }

    int ok = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            if (i > 0 && i < x - 1 && j > 0 && j < x - 1) {
                if (vec[i][j] == '1') {
                    ok = 0;
                }
            } else {
                if (vec[i][j] == '0') {
                    ok = 0;
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
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