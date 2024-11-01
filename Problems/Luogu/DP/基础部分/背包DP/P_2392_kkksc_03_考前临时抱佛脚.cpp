#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    const int N = 4;
    vector<int> vec(N);
    for (int& v : vec) {
        cin >> v;
    }

    int ans = 0;
    for (int k = 0; k < N; ++k) {
        vector<int> res(vec[k]);
        int sum = 0;
        for (int& v : res) {
            cin >> v;
            sum += v;
        }

        const int m = sum / 2;
        vector<int> f(m + 1);
        for (int i = 0; i < vec[k]; ++i) {
            for (int j = m; j >= res[i]; --j) {
                f[j] = max(f[j], f[j - res[i]] + res[i]);
            }
        }
        ans += max(f[m], sum - f[m]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}