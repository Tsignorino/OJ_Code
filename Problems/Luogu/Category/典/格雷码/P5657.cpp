#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    unsigned long long k;
    cin >> n >> k;

    k ^= k >> 1;
    while (~--n) {
        cout << (k >> n & 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
