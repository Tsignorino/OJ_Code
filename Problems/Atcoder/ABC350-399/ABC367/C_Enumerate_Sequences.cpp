#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> res(n);
    auto dfs = [&](auto&& self, int i, int sum) -> void {
        if (i == n) {
            if (sum % k == 0) {
                for (int& val : res) {
                    cout << val << " ";
                }
                cout << "\n";
            }
            return;
        }

        for (res[i] = 1; res[i] <= vec[i]; ++res[i]) {
            self(self, i + 1, sum + res[i]);
        }
    };

    dfs(dfs, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}