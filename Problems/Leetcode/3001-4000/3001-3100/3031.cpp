#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**

把第二题的 KMP 拿过来用了，超时；然后又想到前缀匹配的 Trie，超空间。。
甚至去二分答案。

不过想了想，Trie 的话，还是一个个匹配，时间没优化，还浪费空间。
二分根本没有单调性，实现不了。

看来还是对算法不够了解，或许有前些天不断练习的影响。

回想：
如果对 KMP 本身修改一下，是不是能通过啊，毕竟思路相似
碍于能力有限，只是一些想法。。
（遐想中：Trie 路径二分匹配？时间会不会好一些）

*/

class Solution {
private:
    vector<int> z_func(string s) {
        int n = s.size();
        vector<int> z(n);

        // l, r 表示 Z-box 的左右端点，在匹配的过程中，保证 l <= i
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            //* z[i-l] 表明了 “匹配了多少个字符” 以及 “到哪个字符不匹配”
            // z[i - l] < r - i + 1 表示：匹配段不超过 Z-box 最右端
            if (i <= r && z[i - l] < r - i + 1) {
                z[i] = z[i - l];
            } else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    z[i]++;
                }
            }

            // 更新 新匹配段 Z-box 的左右端点
            if (i + z[i] - 1 > r) {
                l = i, r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    //* 贴板子的写法
    int minimumTimeToInitialState_1(string word, int k) {
        int n = word.size();
        vector<int> Z(z_func(word));

        int i = 1;
        while (i * k < n) {
            if (Z[i * k] == n - i * k) {
                return i;
            } else {
                i++;
            }
        }
        return i;
    }

public:
    //* 在板子上修改
    int minimumTimeToInitialState(string s, int k) {
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r && z[i - l] < r - i + 1) {
                z[i] = z[i - l];
            } else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    z[i]++;
                }
            }

            if (i + z[i] - 1 > r) {
                l = i, r = i + z[i] - 1;
            }

            if (i % k == 0 && z[i] == n - i) {
                return i / k;
            }
        }

        return (n - 1) / k + 1;
    }
};