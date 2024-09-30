#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    set<int> set;
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
        set.insert(v);
    }

    ranges::sort(a);

    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] == 1) {
            cout << "Yes\n";
            return;
        }

        bool flag = true;
        for (int j = a[i - 1] + 1; j < a[i]; ++j) {
            if (set.contains(j)) {
                flag = false;
            }
        }
        if (flag) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
