#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<ll> vec(3, 1);
    for (int i = 0; i < n - 1; ++i) {
        if (vec[0] == vec[2]) {
            vec[2] = vec[2] * 10 + 1;
            vec[0] = vec[1] = 1;
        } else if (vec[0] == vec[1]) {
            vec[1] = vec[1] * 10 + 1;
            vec[0] = 1;
        } else {
            vec[0] = vec[0] * 10 + 1;
        }
    }
    cout << accumulate(vec.begin(), vec.end(), 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}