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

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int i = 0, j = n - 1;
    int l = 1, r = n;
    while (r - l + 1 >= 4) {
        if (vec[i] == l) {
            i++;
            l++;
        } else if (vec[i] == r) {
            i++;
            r--;
        } else if (vec[j] == l) {
            j--;
            l++;
        } else if (vec[j] == r) {
            j--;
            r--;
        } else {
            cout << i + 1 << " " << j + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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