#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        int n, m;
        cin >> n >> m;

        long long s = 1;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            s *= x;
        }

        if (2023 % s == 0) {
            cout << "Yes\n";
            cout << 2023 / s;
            for (int i = 1; i < m; ++i) {
                cout << " 1";
            }
            cout << "\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}