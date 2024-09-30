#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    int n;
    cin >> n >> s;

    if (n != 5) {
        cout << "NO\n";
        return;
    }

    string name("Timur");
    sort(name.begin(), name.end());

    sort(s.begin(), s.end());

    cout << (s == name ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
