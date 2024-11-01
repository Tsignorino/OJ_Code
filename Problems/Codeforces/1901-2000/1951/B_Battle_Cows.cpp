#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    // 和第二个换
    int res1 = 0;
    swap(vec[k], vec[1]);
    if (vec[1] > vec[0]) {
        res1++;
        for (int i = 2; i < n; ++i) {
            if (vec[i] > vec[1]) {
                break;
            }
            res1++;
        }
    }
    swap(vec[k], vec[1]);

    // 和第一个比它大的换
    for (int i = 0; i < k; ++i) {
        if (vec[i] > vec[k]) {
            int res2 = i != 0;
            swap(vec[i], vec[k]);
            for (int j = i + 1; j < n; ++j) {
                if (vec[j] > vec[i]) {
                    cout << max(res1, res2) << "\n";
                    return;
                }
                res2++;
            }
        }
    }
    cout << res1 << "\n";
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