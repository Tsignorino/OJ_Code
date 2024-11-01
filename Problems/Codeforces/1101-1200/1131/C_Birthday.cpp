#include <bits/stdc++.h>

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

    sort(vec.begin(), vec.end());

    vector<int> res(n);
    for (int i = 0, p = 0, q = n - 1; i < n; ++i) {
        (i % 2 == 0 ? res[p++] : res[q--]) = vec[i];
    }

    for (int& val : res) {
        cout << val << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
