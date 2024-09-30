#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for (int& v : hours) {
            cnt += v >= target;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    return 0;
}