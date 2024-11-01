#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << -1 << "\n";
        return;
    }

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    cout << (n + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}