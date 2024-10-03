#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int h, w;
    cin >> h >> w;

    vector a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector b(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    const int inf = 1e9;
    int ans = inf;

    vector<int> row(h);
    iota(row.begin(), row.end(), 0);
    do {
        vector<int> col(w);
        iota(col.begin(), col.end(), 0);

        do {
            int ok = 1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (a[row[i]][col[j]] != b[i][j]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                int inv = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = i + 1; j < h; j++) {
                        inv += (row[i] > row[j]);
                    }
                }
                for (int i = 0; i < w; i++) {
                    for (int j = i + 1; j < w; j++) {
                        inv += (col[i] > col[j]);
                    }
                }
                ans = min(ans, inv);
            }
        } while (ranges::next_permutation(col).found);

    } while (ranges::next_permutation(row).found);

    cout << (ans == inf ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}