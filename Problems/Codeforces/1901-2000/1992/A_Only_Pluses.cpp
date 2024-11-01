#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    vector<int> vec(3);
    for (int& v : vec) {
        cin >> v;
    }

    for (int i = 0; i < 5; ++i) {
        ranges::sort(vec);
        vec[0]++;
    }

    int ans = 1;
    for (int& v : vec) {
        ans *= v;
    }
    cout << ans << "\n";
}

void origin_solve() {
    int a, b, c;
    cin >> a >> b >> c;

    multiset<int> set;
    set.emplace(a);
    set.emplace(b);
    set.emplace(c);
    for (int i = 0; i < 5; ++i) {
        int v = *set.begin();
        set.extract(v);
        set.emplace(v + 1);
    }

    int ans = 1;
    for (auto& v : set) {
        ans *= v;
    }
    cout << ans << "\n";

    // int mx = a * b * c;
    // for (int i = 0; i <= 5; ++i) {
    //     for (int j = 0; j <= 5 - i; ++j) {
    //         int k = 5 - i - j;
    //         if (k < 0) {
    //             continue;
    //         }
    //         mx = max(mx, (a + i) * (b + j) * (c + k));
    //     }
    // }
    // cout << mx << "\n";
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