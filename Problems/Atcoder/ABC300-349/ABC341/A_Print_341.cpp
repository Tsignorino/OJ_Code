#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n * 2 + 1; ++i) {
        cout << (i & 1 ^ 1);
    }
}

/*
python:

n = int(input())
print("0".join("1" * (n + 1)))
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}