#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int a = 0, b = 1023;
    while (n--) {
        char ch;
        int v;
        cin >> ch >> v;

        if (ch == '^') {
            a ^= v, b ^= v;
        } else if (ch == '|') {
            a |= v, b |= v;
        } else {
            a &= v, b &= v;
        }
    }
    // 0: (&1: 0, &0: 0, ^1: 1, ^0: 0, |1: 1, |0: 0)
    // 1: (&1: 1, &0: 0, ^1: 0, ^0: 1, |1: 1, |0: 0)
    cout << 2 << "\n";
    cout << "& " << (a ^ b) << "\n";
    cout << "^ " << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}