#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    sort(vec.begin(), vec.end());

    if (vec[0] != vec[1]) {
        cout << "YES\n";
    } else {
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if (vec[i] % vec[0] != 0) {
                flag = true;
            }
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
