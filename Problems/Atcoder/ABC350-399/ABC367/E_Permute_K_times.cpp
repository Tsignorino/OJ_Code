#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
        v--;
    }

    vector<int> res(n);
    iota(res.begin(), res.end(), 0);

    while (k > 0) {
        if (k % 2 == 1) {
            for (int i = 0; i < n; i++) {
                res[i] = vec[res[i]];
            }
        }
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = vec[vec[i]];
        }
        vec = std::move(tmp);
        k /= 2;
    }

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        b[i] = a[res[i]];
        cout << b[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}