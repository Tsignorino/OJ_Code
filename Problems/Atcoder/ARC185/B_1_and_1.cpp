#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<ll> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);

    int u = sum / n, v = sum % n;
    int ok = 1;
    for (int i = 0; i < n - 1; ++i) {
        int up = u + (n - 1 - i < v);
        if (vec[i] > up) {
            ok = 0;
            break;
        }
        vec[i + 1] -= up - vec[i];
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