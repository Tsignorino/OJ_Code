#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int has1 = m, has2 = 0, buy = 0;
    for (char ch : s) {
        if (ch == '0') {
            has1 = m;
            has2 = buy;
        } else if (ch == '1') {
            if (has1 > 0) {
                has1--;
            } else if (has2 > 0) {
                has2--;
            } else {
                buy++;
            }
        } else {
            if (has2 > 0) {
                has2--;
            } else {
                buy++;
            }
        }
    }
    cout << buy << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}