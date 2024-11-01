#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
如果 n >= m，可以先分给每人 floor(n/m) 个苹果。
下面讨论 n < m 的情况。

由于苹果块的重量是从 1 开始不断减半的，所以每个人分到的苹果重量的既约分数的分母一定是 2 的幂。如果不是，直接输出 -1。
例如把 15 个苹果分给 20 个人，和把 3 个苹果分给 4 个人是类似的。
计算出把 3 个苹果分给 4 个人的答案，再乘以 5，就得到了把 15 个苹果分给 20 个人的答案。
因此，如果 gcd(n,m) > 1，可以先把 n 和 m 都除以 gcd，最后把答案再乘以 gcd。

下面假设 gcd(n,m)=1 且 m=2^k。
把 3 个苹果分给 4 个人，我们可以先把每个苹果切一刀，得到 6 个 1/2 苹果。
接下来切苹果的次数，等价于：把 6 个苹果分给 4 个人的最少切苹果次数。
这和原问题是一样的，可以用递归/迭代解决。
具体来说：只要 n > 0 就不断循环，每次把 n 加到答案中，然后更新 n 为 n * 2 % m。
*/

void solve() {
    int n, m;
    cin >> n >> m;

    n %= m;

    int g = gcd(n, m);
    n /= g;
    m /= g;

    if (m & (m - 1)) {
        cout << -1 << "\n";
        return;
    }

    ll ans = 0;
    while (n > 0) {
        ans += n;
        n = n * 2 % m;
    }
    cout << ans * g << "\n";
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