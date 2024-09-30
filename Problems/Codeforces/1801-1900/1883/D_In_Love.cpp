#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int q;
    cin >> q;

    multiset<int> ll, rr;
    while (q--) {
        char Op;
        int l, r;
        cin >> Op >> l >> r;

        if (Op == '+') {
            ll.emplace(l);
            rr.emplace(r);
        } else {
            ll.extract(l);
            rr.extract(r);
        }

        cout << (!ll.empty() && *ll.rbegin() > *rr.begin() ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}