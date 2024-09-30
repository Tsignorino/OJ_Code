#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n), a(n);
    for (int i = 1; i < n; ++i) {
        cin >> vec[i];
    }
    vec.emplace_back(0);

    a[0] = vec[1] + 1;
    for (int i = 1; i < n; ++i) {
        a[i] = vec[i] + (vec[i + 1] / a[i - 1] + 1) * a[i - 1];
    }
    for (int& v : a) {
        cout << v << " ";
    }
    cout << "\n";
}

void mysolve() {
    int n;
    cin >> n;

    int pre = 1e8;
    cout << pre << " ";
    for (int i = 0; i < n - 1; ++i) {
        int v;
        cin >> v;
        pre += v;
        cout << pre << " ";
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