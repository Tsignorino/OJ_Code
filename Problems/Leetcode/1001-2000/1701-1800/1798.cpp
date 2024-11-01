#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        ranges::sort(coins);

        int m = 0;
        for (int& v : coins) {
            if (m >= v - 1) {
                m += v;
            } else {
                break;
            }
        }
        return m + 1; // [0, m]
    }
};

int main() {
    Solution sol;

    return 0;
}