#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
    }

    int ra = 0, rb = 0, pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            ra += a[i];
        }
        if (a[i] < b[i]) {
            rb += b[i];
        }

        if (a[i] == 1 && b[i] == 1) {
            pos++;
        }
        if (a[i] == -1 && b[i] == -1) {
            neg++;
        }
    }

    for (int i = 0; i < neg; ++i) {
        (ra > rb ? ra : rb)--;
    }
    for (int i = 0; i < pos; ++i) {
        (ra < rb ? ra : rb)++;
    }

    cout << min(ra, rb) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
