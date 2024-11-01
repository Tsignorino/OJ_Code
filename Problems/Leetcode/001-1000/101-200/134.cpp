#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
            从谷底的后一个点开始爬山，意味着如果你开始的位置在最低点之后，整个旅程都是向上的或平坦的
        */
        int ans = 0, mn = 0, s = 0;
        for (int i = 0; i < gas.size(); ++i) {
            s += gas[i] - cost[i];
            if (s < mn) {
                mn = s;
                ans = i + 1;
            }
        }
        return s < 0 ? -1 : ans;
    }
};

int main() {
    Solution sol;

    return 0;
}