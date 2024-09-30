#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int num;
    cin >> num;

    int sum = 0; // sum 统计花出去的量
    while (num) {
        if (num <= 9) {
            sum += num;
            num = 0;
        } else {
            sum += num - num % 10;
            num = num % 10 + num / 10;
        }
    }

    cout << sum << "\n";
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
