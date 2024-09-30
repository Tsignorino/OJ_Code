#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

int Ask(int a, int b) {
    cout << format("? {} {}", a, b) << endl;
    int val;
    cin >> val;
    return val;
}
void Ans(int a) {
    cout << format("! {}", a) << endl;
}

void solve() {
    int l = 1, r = 999;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (Ask(1, mid) == mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    Ans(r);
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