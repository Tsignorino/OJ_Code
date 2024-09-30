#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int i = 0, ans = 0;
    while (i < n) {
        if (vec[i] == 0) {
            ans++;
            i++;
            continue;
        }

        int idx = i;
        bool ok = false;
        for (; i < n && vec[i] > 0; ++i) {
            if (vec[i] == 2) {
                ok = true;
            }
        }
        ans++;

        if (idx > 0 && vec[idx - 1] == 0) {
            ans--;
            if (ok == false) {
                continue;
            }
        }
        if (i < n) {
            vec[i] = 1; // i 指向下一段的 0
            i++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
