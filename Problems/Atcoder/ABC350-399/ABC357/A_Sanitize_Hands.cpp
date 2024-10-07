#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (m >= vec[i]) {
            m -= vec[i];
            res++;
        } else {
            break;
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
