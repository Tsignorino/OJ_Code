#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    vector<int> res(n + 1); // 统计倍数的出现次数
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) {
            cnt[val]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int k = i; k <= n; k += i) {
            res[k] += cnt[i];
        }
    }
    cout << *max_element(res.begin(), res.end()) << "\n";
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
