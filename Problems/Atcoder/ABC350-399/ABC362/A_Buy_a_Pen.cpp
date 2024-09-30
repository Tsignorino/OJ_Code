#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    string s;
    cin >> a >> b >> c >> s;

    if (s == "Blue") {
        cout << min(a, b) << "\n";
    }
    if (s == "Red") {
        cout << min(b, c) << "\n";
    }
    if (s == "Green") {
        cout << min(a, c) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}