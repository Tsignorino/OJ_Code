#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int ans = 1, res = 0;
    for (int& v : vec) {
        if (res + v <= x) {
            res += v;
        } else {
            res = v;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
