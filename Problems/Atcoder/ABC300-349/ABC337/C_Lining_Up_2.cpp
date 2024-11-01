#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;

        if (val == -1) {
            id = i;
        } else {
            vec[val] = i;
        }
    }

    while (n--) {
        cout << id << " ";
        id = vec[id];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}