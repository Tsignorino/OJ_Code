#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    vector<int> vec;
    int t;
    while (cin >> t) {
        vec.emplace_back(t);
    }

    for (int i = vec.size() - 1; i >= 0; --i) {
        cout << vec[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}