#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, T;
    cin >> n >> T;
    vector<int> vec(T + 1);
    for (int i = 1; i <= T; ++i) {
        cin >> vec[i];
    }

    vector<int> cnt_r(n), cnt_c(n);
    int d1 = 0, d2 = 0;
    for (int i = 1; i <= T; ++i) {
        vec[i]--;

        int r = vec[i] / n, c = vec[i] % n;
        cnt_r[r]++;
        cnt_c[c]++;
        d1 += c == r;
        d2 += c + r == n - 1;

        if (cnt_r[r] == n || cnt_c[c] == n || d1 == n || d2 == n) {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
