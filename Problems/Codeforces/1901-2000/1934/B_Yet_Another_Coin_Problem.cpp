#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

const vector<int> res {1, 3, 6, 10, 15};

void solve() {
    int n;
    cin >> n;

    int ans = n;
    for (int a = 0; a <= 2; ++a) {
        for (int b = 0; b <= 1; ++b) {
            for (int c = 0; c <= 4; ++c) {
                for (int d = 0; d <= 2; ++d) {
                    int res = n - a - b * 3 - c * 6 - d * 10;
                    if (res >= 0 && res % 15 == 0) {
                        ans = min(ans, res / 15 + a + b + c + d);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
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