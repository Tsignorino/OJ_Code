#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> vec(n, 1);
    for (int i = 0; i < n; i++) {
        int cur = 1;
        for (int j = i; j < n - 1; j++) {
            if (s[j] == 'R') {
                break;
            }
            if (s[j] == 'L') {
                cur++;
            }
        }
        if (cur > vec[i]) {
            vec[i] = cur;
        }

        cur = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == 'L') {
                break;
            }
            if (s[j] == 'R') {
                cur++;
            }
        }
        if (cur > vec[i]) {
            vec[i] = cur;
        }
    }

    for (int& v : vec) {
        cout << v << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
