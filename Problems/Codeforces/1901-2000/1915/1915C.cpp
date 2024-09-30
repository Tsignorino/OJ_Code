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
        int n, num;
        cin >> n;
        ll sum = 0LL;
        while (n--) {
            cin >> num;
            sum += num;
        }

        // 二分判断 sum 是不是平方数
        // ll l = 1, r = sum;
        // bool flag = true;
        // while (l < r) { // [l, r)
        //     ll mid = l + (r - l) / 2;
        //     if (mid * mid < sum) {
        //         l = mid + 1;
        //     } else if (mid * mid > sum) {
        //         r = mid;
        //     } else {
        //         puts("YES");
        //         flag = false;
        //         break;
        //     }
        // }

        // if (flag) {
        //     puts("NO");
        // }
        ll s = sqrt(sum);
        if (s * s == sum) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}