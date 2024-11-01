#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> vec(n + 1);
        ranges::copy(cost, vec.begin() + 1);

        /*
            考虑根到两个互为兄弟节点的叶子的两条路径 ==> 需要修改叶子节点的值
            考虑非叶子的兄弟节点，可以把路径和从叶子向上传
        */
        int ans = 0;
        for (int i = n / 2; i > 0; --i) {
            ans += abs(vec[2 * i + 1] - vec[2 * i]);
            vec[i] += max(vec[2 * i + 1], vec[2 * i]);
        }

        return ans;
    }
};