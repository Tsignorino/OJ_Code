#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
* 给您一个整数 n 和三个字符串 a, b, c，每个字符串由 n 个小写拉丁字母组成。

令模板为由 n 个小写 和/或 大写拉丁字母组成的字符串 t。如果以下条件适用于从 1 到 n 的所有 i，则字符串 s 与模板 t 匹配：
    如果模板的第 i 个字母是 小写，则 si 必须与 ti 相同；
    如果模板的第 i 个字母是 大写，则 si 必须与 ti 的 小写版本 不同。

确定是否存在模板 t，使得字符串 a 和 b 与其匹配，而字符串 c 则不匹配。
*/

void func() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    // a[i] == b[i]     小 大
    // a[i] != b[i]     大
    // 对于 a[i]、b[i] 两个字符串来说，一定存在匹配的模式串 t

    int match = 0; // c 匹配字符的数量
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (c[i] != a[i]) { // t[i] 选择 c[i] 对应的大写字母即可
                puts("YES");
                break;
            } else { // 无可奈何，要想让 a[i]、b[i] 匹配，c[i] 只能匹配
                match++;
            }
        } else {
            if (c[i] != a[i] && c[i] != b[i]) { // a[i]、b[i]、c[i] 均不相等
                puts("YES");
                break;
            } else { // c[i] 和 a[i] 或 b[i] 相等，要想让 a[i]、b[i] 匹配，c[i] 只能匹配
                match++;
            }
        }

        if (match == n) {
            puts("NO");
        }
    }
}

void solve() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != c[i] && b[i] != c[i]) {
            flag = false;
            puts("YES");
            break;
        }
    }

    if (flag) {
        puts("NO");
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
