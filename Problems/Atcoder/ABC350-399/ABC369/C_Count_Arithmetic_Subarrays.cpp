#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    for (int i = 1; i < n; i++) {
        vec[i - 1] -= vec[i];
    }

    ll ans = n;
    vec[n - 1] = 1e9 + 10;
    for (int i = 0, j; i < n - 1; i = j + 1) {
        j = i;
        while (vec[j + 1] == vec[i]) {
            ++j;
        }
        ans += (j - i + 2) * 1ll * (j - i + 1) / 2;
    }
    cout << ans << "\n";
}

void my_solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1;) {
        int j = i + 1, k = i + 1;
        while (j < n) {
            if (vec[j] - vec[j - 1] == vec[k] - vec[k - 1]) {
                j++;
            } else {
                break;
            }
        }
        ll cnt = j - i;
        ans += (cnt + 1) * cnt / 2 - 1; // 去掉每个等差数列单独的第一项
        i = j - 1;
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}