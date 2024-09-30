#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0, cur = 0, down = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int l = s.find('W');
        if (l == -1) {
            continue;
        }

        down = i;

        int r = s.rfind('W');
        if (i % 2 == 0) {
            ans += (cur <= l ? r - cur : cur - l + r - l);
            cur = r;
        } else {
            ans += (cur >= r ? cur - l : r - cur + r - l);
            cur = l;
        }
    }
    cout << ans + down << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}