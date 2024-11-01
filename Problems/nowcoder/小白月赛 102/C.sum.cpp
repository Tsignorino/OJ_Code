#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    int sum = accumulate(vec.begin(), vec.end(), 0);
    const int x = 1e4;
    int ans = 0;
    if (sum < s) {
        for (int i = 0; i < n; ++i) {
            int d = min(x - vec[i], s - sum);
            sum += d;
            ans++;
            if (sum >= s) {
                break;
            }
        }
    } else if (sum > s) {
        for (int i = n - 1; i >= 0; --i) {
            int d = min(vec[i] + x, sum - s);
            sum -= d;
            ans++;
            if (sum <= s) {
                break;
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