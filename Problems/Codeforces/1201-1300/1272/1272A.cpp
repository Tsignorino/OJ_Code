#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int arr[3]{a, b, c};
    sort(arr, arr + 3);

    cout << max(abs(arr[0] - arr[2]) + abs(arr[1] - arr[2]) + abs(arr[0] - arr[1]) - 4, 0) << "\n";
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
