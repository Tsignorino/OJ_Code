#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    const int N = 8;

    vector<int> row(N, 1), col(N, 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    cout << accumulate(row.begin(), row.end(), 0) * accumulate(col.begin(), col.end(), 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}