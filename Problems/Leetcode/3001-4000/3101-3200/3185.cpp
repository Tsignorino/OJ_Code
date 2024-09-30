#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> cnt(24);
        for (int h : hours) {
            // i < j
            ans += cnt[(24 - h % 24) % 24];
            cnt[h % 24]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}