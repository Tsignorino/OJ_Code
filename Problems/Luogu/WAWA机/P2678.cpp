#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int L, n, m;
    cin >> L >> n >> m;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    vec.insert(vec.begin(), 0);
    vec.emplace_back(L);

    int l = 0, r = L + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        int tot = 0, now = 0;
        for (int i = 1; i <= n + 1; ++i) {
            if (vec[i] - vec[now] < mid) {
                tot++;
            } else {
                now = i;
            }
        }

        if (tot > m) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
