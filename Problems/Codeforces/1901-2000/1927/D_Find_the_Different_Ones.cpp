#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> nxt(n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        nxt[i] = vec[i] == vec[i + 1] ? nxt[i + 1] : i + 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if (nxt[l] < r) {
            cout << format("{} {}\n", l + 1, nxt[l] + 1);
        } else {
            cout << format("{} {}\n", -1, -1);
        }
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
