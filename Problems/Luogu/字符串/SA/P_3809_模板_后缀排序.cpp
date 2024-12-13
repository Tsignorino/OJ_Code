// Date: 2024-11-28  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct suffixArray {
    int n;
    // sa —— 后缀数组（sa[i] 表示排序为 i 的后缀编号）
    // 把字符串 str 的所有后缀按字典序排序，sa[i] 表示排名为 i 的后缀的开头下标
    // rk —— 名次数组（rk[i] 表示后缀 i 的排名）
    // rk[i] 表示当前长度下，i 开始的后缀的排名。
    vector<int> sa, rk, lc;

    suffixArray(const string& s) : n(s.size()), sa(n), lc(n - 1), rk(n) {
        iota(sa.begin(), sa.end(), 0);
        // 按所有后缀的第一个字符排序
        sort(sa.begin(), sa.end(), [&](int a, int b) { return s[a] < s[b]; });
        rk[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        }

        vector<int> cnt(n), tmp;
        tmp.reserve(n);
        for (int k = 1; rk[sa[n - 1]] < n - 1; k <<= 1) {
            // 首先添加长度为 k 的后缀，然后添加其余后缀的下一半
            tmp.clear();
            for (int i = 0; i < k; i++) {
                tmp.push_back(n - k + i);
            }
            for (int i : sa) {
                if (i >= k) {
                    tmp.push_back(i - k);
                }
            }

            // 使用计数排序对 tmp 中的后缀进行排序。
            // 首先计数每个排名的出现次数，然后计算排名的累积计数。
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++) {
                cnt[rk[i]]++;
            }
            for (int i = 1; i < n; i++) {
                cnt[i] += cnt[i - 1];
            }

            // 根据计数数组 cnt 将 tmp 中的后缀按排名顺序放入 sa。
            for (int i = n - 1; i >= 0; i--) {
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            }

            // tmp 现在存储旧的排名，重新计算排名
            swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            }
        }

        // 最长公共前缀（LCP）
        for (int i = 0, j = 0; i < n; i++) {
            if (rk[i] == 0) {
                j = 0;
            } else {
                j -= j > 0;
                while (i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]) {
                    j++;
                }
                lc[rk[i] - 1] = j;
            }
        }
    }
};

void solve() {
    string s;
    cin >> s;

    suffixArray SA(s);
    for (int& v : SA.sa) {
        cout << v + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}