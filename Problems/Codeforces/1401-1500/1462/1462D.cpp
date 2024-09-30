#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int nums[n], sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    // 最多进行 n-1 次操作
    for (int l = n; l > 0; --l) {
        if (sum % l) { // 不能整除
            continue;
        }

        int div = sum / l, cur = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            cur += nums[i];
            if (cur == div) { // 构造出来了一个 div
                cur = 0;
            } else if (cur > div) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << n - l << "\n";
            break;
        }
    }
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
