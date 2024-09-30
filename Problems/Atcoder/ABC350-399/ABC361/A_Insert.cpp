#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        cout << val << " ";
        if (i == k - 1) {
            cout << x << " ";
        }
    }
}

/*
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vec.insert(vec.begin() + k, x);

    for (int& v : vec) {
        cout << v << " ";
    }
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
