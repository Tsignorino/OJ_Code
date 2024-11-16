#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    string s;
    cin >> s;

    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum -= a[i];
        if (s[i] == '1') {
            ans = max(ans, sum);
            sum += a[i];
        }
    }
    cout << max(ans, sum) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}