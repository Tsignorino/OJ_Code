#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int k;
    cin >> k;

    for (int i = n - 1; i > 0; --i) {
        c[i - 1] = min(c[i - 1], c[i]);
    }

    int a = k;
    for (int i = 0; i < n; ++i) {
        int add = c[i] - (i ? c[i - 1] : 0);
        a = min(a, add ? k / add : a);
        k -= add * a;
        cout << a << " ";
    }
    cout << "\n";
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