#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int bulbSwitch(int n) {
        /*
            1. 第 i 轮改变编号为 i 的倍数的灯泡的状态
            2. 打开状态 <=> 切换状态为奇数次（次数等于约数的个数）
            3. 约数个数为奇数 <=> 完全平方数（约数成对出现）
            4. [1, n] 中完全平方数的个数为 根号n（下取整）
         */
        return (int) sqrt(n);
    }
};

int main() {
    Solution sol;

    return 0;
}