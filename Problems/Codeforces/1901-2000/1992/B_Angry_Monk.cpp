#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(k);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    cout << accumulate(vec.begin(), vec.end() - 1, 0ll) * 2 - k + 1 << "\n";
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