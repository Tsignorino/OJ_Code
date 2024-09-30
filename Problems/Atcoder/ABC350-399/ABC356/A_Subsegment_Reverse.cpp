#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);
    reverse(vec.begin() + l - 1, vec.begin() + r);
    for (int& v : vec) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
