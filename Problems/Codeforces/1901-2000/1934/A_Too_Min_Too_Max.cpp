#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    // |a[i] - a[j]| + |a[j] - a[k]| + |a[k] - a[l]| + |a[l] - a[i]|

    /*  Solution 1: BF
        possible vals:
            i j k l    ans = 2 * (a[l] - a[i])
            i j l k    ans = 2 * (a[k] - a[i])
            i k j l    ans = 2 * (a[l] + a[k] - a[j] - a[i])
            i k l j    ans = 2 * (a[l] + a[j] - a[i] - a[k])
            i l k j    ans = 2 * (a[j] - a[l])
            i l j k    ans = 2 * (a[k] - a[i])
            由于 四个数循环作差取绝对值，其余字母开头的均与上面的值重复
        明显，最大值为 ans = 2 * (a[l] + a[k] - a[j] - a[i]) = 2 * (a[n - 1] + a[n - 2] - a[1] - a[0])
    */

    /*  Solution 2: greedy
        定义 i <= j <= k <= l
        按正常顺序求解，中间的值会出现抵消，如果交换中间两个值，值会变大：
            交换中间两个数，不影响 |a[j] - a[k]| + |a[l] - a[i]|
            原本的 |a[i] - a[j]| + |a[k] - a[l]| = a[j] - a[i] + a[l] - a[k]
            变成了 |a[i] - a[k]| + |a[j] - a[l]| = a[k] - a[i] + a[l] - a[j]
            增加了 delta = a[k] * 2 - a[j] * 2

        因而，固定 i 和 l，交换 j 和 k 可以获得更大的值，为取到最大值，需要让 a[k] - a[j] 足够大
        ==> 最大值为 2 * (a[n - 1] + a[n - 2] - a[1] - a[0])
    */
    cout << 2 * (a[n - 1] + a[n - 2] - a[1] - a[0]) << "\n";
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