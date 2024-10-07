#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        s.emplace(v);
    }

    cout << (s.size() == 1 ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}