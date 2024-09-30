#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ranges::sort(s);

    int cnt = 0;
    do {
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            string t = s.substr(i, k);
            if (t.size() == k) {
                auto tt(t);
                ranges::reverse(tt);
                if (t == tt) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok == 1) {
            cnt++;
        }
    } while (ranges::next_permutation(s).found);

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}