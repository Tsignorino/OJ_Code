#include <bits/stdc++.h>

using namespace std;

/*
    https://www.luogu.com.cn/problem/P3173
*/

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        vector<pair<int, int>> vec;
        for (int& v : hCut) {
            vec.emplace_back(v, 0);
        }
        for (int& v : vCut) {
            vec.emplace_back(v, 1);
        }

        ranges::sort(vec, greater<>());

        long long sum1 = accumulate(hCut.begin(), hCut.end(), 0ll);
        long long sum2 = accumulate(vCut.begin(), vCut.end(), 0ll);

        long long cost = 0;
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

    vector<int> hCut {1, 3}, vCut {5};
    sol.minimumCost(3, 2, hCut, vCut);

    return 0;
}