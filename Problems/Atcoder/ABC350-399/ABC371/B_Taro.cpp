#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    while (q--) {
        int v;
        char ch;
        cin >> v >> ch;
        v--;

        if (vec[v] == 0 && ch == 'M') {
            cout << "Yes\n";
            vec[v] = 1;
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}