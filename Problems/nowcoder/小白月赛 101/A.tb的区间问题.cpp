#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += vec[n - 1 - i];
    }

    ll mn = sum;
    for (int i = 0; i < k; ++i) {
        sum += vec[i];
        sum -= vec[n - k + i];

        mn = min(mn, sum);
    }

    cout << accumulate(vec.begin(), vec.end(), 0ll) - mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}