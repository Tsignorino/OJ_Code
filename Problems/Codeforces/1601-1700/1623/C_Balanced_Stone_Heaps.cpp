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

    auto check = [&](int x) -> bool {
        vector<int> ret(vec);
        for (int i = n - 1; i >= 2; --i) {
            if (ret[i] < x) {
                return false;
            }

            // ! 由于是正序遍历，移动的石头数量不能超过原来的数量
            int diff = min(vec[i], ret[i] - x) / 3;
            ret[i - 1] += diff;
            ret[i - 2] += diff * 2;
        }
        return ret[0] >= x && ret[1] >= x;
    };

    int l = *min_element(vec.begin(), vec.end()) - 1;
    int r = *max_element(vec.begin(), vec.end()) + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        (check(mid) ? l : r) = mid;
    }
    cout << l << "\n";
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
