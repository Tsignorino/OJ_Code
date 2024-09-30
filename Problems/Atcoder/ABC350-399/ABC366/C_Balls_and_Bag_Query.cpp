#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    while (n--) {
        int Op;
        cin >> Op;

        if (Op == 3) {
            cout << mp.size() << "\n";
            continue;
        }

        int x;
        cin >> x;
        if (Op == 1) {
            mp[x]++;
        }

        if (Op == 2) {
            if (--mp[x] == 0) {
                mp.erase(x);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}