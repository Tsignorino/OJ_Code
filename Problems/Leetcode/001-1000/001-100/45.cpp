#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), mx = 0, end = 0, cnt = 0;
        for (int i = 0; i < n - 1; ++i) { // 不访问最后一个元素
            if (mx >= i) {
                mx = max(mx, i + nums[i]);
                if (i == end) {
                    end = mx;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    return 0;
}