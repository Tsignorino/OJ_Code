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

    for (int i = 0; i < n - 1; ++i) {
        int s, t;
        cin >> s >> t;

        vec[i + 1] += vec[i] / s * t;
    }

    cout << vec.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}