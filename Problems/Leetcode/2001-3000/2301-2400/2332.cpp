#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        ranges::sort(buses);
        ranges::sort(passengers);

        int j = 0, c = 0;
        for (int& t : buses) {
            for (c = capacity; c && j < passengers.size() && passengers[j] <= t; --c) {
                j++;
            }
        }

        j--;
        int ans = c ? buses.back() : passengers[j];
        while (j >= 0 && ans == passengers[j]) {
            ans--;
            j--;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}