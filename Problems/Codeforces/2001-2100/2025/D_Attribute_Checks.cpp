#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    /*
        · f(i, j) 表示前 i 个操作执行之后 "智力" 的值为 j 时的最大值

        记 v = vec[i], 有
            1> v > 0, f(i, j) = f(i-1, j) + (j >= v)               智力
            2> v < 0, f(i, j) = f(i-1, j) + (si - j >= -v)         力量
            3> v = 0, f(i, j) = max(f(i-1, j-1), f(i-1, j))

        1,2 式中，f(i, *) 与 f(i-1, *) 的区别仅在于前后缀整体加 1，可以降维并差分维护
    */
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    vec.emplace_back(0); // "总结" 操作

    vector<int> diff(m + 1);
    vector<int> f(m + 1);
    int s = 0;
    for (int& v : vec) {
        if (v > 0) {
            if (s >= v) {
                diff[v]++;
            }
        } else if (v < 0) {
            if (s >= -v) {
                diff[0]++;
                diff[s + v + 1]--;
            }
        } else {
            s++;

            partial_sum(diff.begin(), diff.end(), diff.begin());
            for (int i = 0; i <= m; ++i) {
                f[i] += diff[i];
            }
            for (int i = m; i > 0; --i) {
                f[i] = max(f[i], f[i - 1]);
            }
            diff.assign(m + 1, 0);
        }
    }
    cout << ranges::max(f) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}