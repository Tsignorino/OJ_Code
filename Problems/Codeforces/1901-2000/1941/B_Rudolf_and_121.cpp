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

    for (int i = 0; i < n; ++i) {
        if (vec[i] < 0) {
            puts("NO");
            return;
        }

        if (i + 2 >= n && vec[i] != 0) {
            puts("NO");
            return;
        }

        if (vec[i] > 0) {
            vec[i + 1] -= 2 * vec[i];
            vec[i + 2] -= vec[i];
            vec[i] = 0;
        }
    }
    puts("YES");

    /* Solution
    bool flag = true;
    for (int i = 0; i < n - 2; ++i) {
        if (vec[i] < 0) {
            flag = false;
            puts("NO");
            return;
        }

        if (vec[i] == 0) {
            continue;
        }

        vec[i + 1] -= 2 * vec[i];
        vec[i + 2] -= vec[i];
        vec[i] = 0;
    }

    if (flag && vec[n - 1] == 0 && vec[n - 2] == 0) {
        puts("YES");
    } else {
        puts("NO");
    }
    */
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
