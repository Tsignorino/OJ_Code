#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int deg[3] {};

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            char s;
            cin >> s;
            if (s == '<') {
                deg[i]++;
            } else {
                deg[j]++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (deg[i] == 1) {
            cout << char('A' + i) << "\n";
        }
    }

    // char c1, c2, c3; // AB AC BC
    // cin >> c1 >> c2 >> c3;
    //
    // if (c1 == '>') {
    //     if (c2 == '>') {
    //         if (c3 == '>') {
    //             cout << "B";
    //         } else {
    //             cout << "C";
    //         }
    //     } else {
    //         cout << "A";
    //     }
    // } else {
    //     if (c2 == '>') {
    //         cout << "A";
    //     } else {
    //         if (c3 == '>') {
    //             cout << "C";
    //         } else {
    //             cout << "B";
    //         }
    //     }
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}