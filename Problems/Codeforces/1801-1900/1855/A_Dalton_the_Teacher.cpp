#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ans += num == i + 1;
    }
    cout << (ans + 1) / 2 << "\n";
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
