#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);

    ranges::sort(vec, greater<>());
    reverse(vec.end() - m, vec.end());

    for (int& v : vec) {
        cout << v << " ";
    }
    cout << "\n";
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