#include <bits/stdc++.h>

using namespace std;

/*

* 相邻合并 <--> 连续子数组合并

* 如果能合并成 0，相当于 操作次数等于长度 - 1
* 如果不能合并成 0，相当于 操作次数等于长度

*/

class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0, mask = 0;

        for (int i = 29; i >= 0; --i) { // 从高位到低位
            mask |= 1 << i;

            int cnt = 0; // 记录合并次数
            int res = -1; // 全为 1
            for (const int& num : nums) {
                res &= num & mask;

                // 如果 res 不为 0，cnt++，否则复原，继续合并下一段
                if (res != 0) {
                    cnt++;
                } else { // 相当于将 cnt 进行了减 1
                    res = -1;
                }

                if (cnt > k) { // 提前终止
                    break;
                }
            }

            if (cnt > k) {
                ans |= 1 << i;
                mask ^= 1 << i; // 置 0，之后不再考虑这一位
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {3, 5, 3, 2, 7};
    int k = 2;
    cout << sol.minOrAfterOperations(nums, k);

    return 0;
}