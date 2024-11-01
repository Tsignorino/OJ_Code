#include <bits/stdc++.h>

using namespace std;

/*
    https://www.luogu.com.cn/problem/P3173
*/

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        vector<pair<int, int>> vec;
        for (int& v : hCut) {
            vec.emplace_back(v, 0);
        }
        for (int& v : vCut) {
            vec.emplace_back(v, 1);
        }

        ranges::sort(vec, greater<>());

        int sum1 = accumulate(hCut.begin(), hCut.end(), 0ll);
        int sum2 = accumulate(vCut.begin(), vCut.end(), 0ll);

        int cost = 0;
        for (auto& [v, c] : vec) {
            if (c == 0) {
                cost += sum2 + v;
                sum1 -= v;
            } else {
                cost += sum1 + v;
                sum2 -= v;
            }
        }
        return cost;
    }
};

int main() {
    Solution sol;

    return 0;
}