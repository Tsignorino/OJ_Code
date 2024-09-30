#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        ranges::sort(people);
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l < r && people[l] + people[r] <= limit) {
                l++;
            }
            r--;
        }
        return n - r - 1;
    }
};

int main() {
    Solution sol;

    return 0;
}