#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& d, int start, int end) {
        if (start > end) {
            swap(start, end);
        }

        int sum = accumulate(d.begin(), d.end(), 0);
        int res = accumulate(d.begin() + start, d.begin() + end, 0);
        return min(res, sum - res);
    }
};

int main() {
    Solution sol;

    return 0;
}