#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        for (int& v : nums) {
            (v < 10 ? s1 : s2) += v;
        }
        return s1 != s2;
    }
};

int main() {
    Solution sol;

    return 0;
}