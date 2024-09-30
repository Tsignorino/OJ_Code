#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

int highbit(int x) {
    return 32 - __builtin_clz(x);
}

//* f(x, y) = (x | y) - y = x & (~y)

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    // 前后缀
    vector<int> pre(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] & (~vec[i]);
    }
    vector<int> suf(n + 1, -1);
    for (int i = n - 1; i >= 0; --i) { // ! 注意下标
        suf[i] = suf[i + 1] & (~vec[i]);
    }

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = pre[i] & vec[i] & suf[i + 1]; // ! 注意不要包含 vec[i]
    }

    int mx = -1, idx = -1;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] > mx) {
            mx = res[i];
            idx = i;
        }
    }

    // ! 错解：按最高有效位排序（最高位相等，比较次高位）
    // ! 选出来最高有效位的那个数字，可能还会有其他数字把最高位置零，这样的贪心是错误的
    // int idx = 0, hb = -1;
    // for (int i = 0; i < n; ++i) {
    //     if (vec[i] == 0) {
    //         continue;
    //     }

    //     int val = highbit(vec[i]);
    //     if (val > hb) {
    //         idx = i;
    //         hb = val;
    //     } else if (val == hb) {
    //         for (int k = val - 1; k >= 0; --k) {
    //             if ((vec[idx] >> k & 1) == (vec[i] >> k & 1)) {
    //                 continue;
    //             }

    //             if ((vec[idx] >> k & 1) < (vec[i] >> k & 1)) {
    //                 idx = i;
    //             }
    //             break;
    //         }
    //     }
    // }

    cout << vec[idx] << " ";
    for (int i = 0; i < n; ++i) {
        if (i == idx) {
            continue;
        }
        cout << vec[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
