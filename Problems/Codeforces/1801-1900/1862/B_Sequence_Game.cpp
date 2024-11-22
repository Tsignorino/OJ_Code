#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (i && a.back() > num) {
            a.emplace_back(1);
        }
        a.emplace_back(num);
    }

    int m = a.size();
    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        cout << a[i] << " \n"[i == m - 1];
    }
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
