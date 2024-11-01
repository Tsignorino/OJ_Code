#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<map<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int k = 0; k < c; ++k) {
            int val;
            cin >> val;
            vec[i][val] = c;
        }
    }

    int x;
    cin >> x;

    vector<int> ans;
    int mn = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        if (vec[i].contains(x)) {
            if (vec[i][x] < mn) {
                mn = vec[i][x];
                ans.clear();
                ans.emplace_back(i + 1);
            } else if (vec[i][x] == mn) {
                ans.emplace_back(i + 1);
            }
        }
    }

    cout << ans.size() << "\n";
    for (int& v : ans) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}