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

    auto check = [&](auto x) {
        map<int, int> cnt;
        for (int i = x; i < n; ++i) {
            cnt[vec[i]]++;
        }
        if (cnt.size() == n - x) {
            return true;
        }
        for (int i = x; i < n; ++i) {
            if (--cnt[vec[i]] == 0) {
                cnt.erase(vec[i]);
            }
            cnt[vec[i - x]]++;
            if (cnt.size() == n - x) {
                return true;
            }
        }
        return false;
    };

    int l = -1, r = n;
    while (l + 1 < r) {
        auto mid = l + (r - l) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}