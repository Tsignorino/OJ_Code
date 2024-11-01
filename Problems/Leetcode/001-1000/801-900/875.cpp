#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(), piles.end()) + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            long long cnt = 0;
            for (const int& p : piles) {
                cnt += (p - 1) / mid + 1;
            }

            if (cnt > h) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return r;
    }
};

int main() {
    Solution sol;

    vector<int> piles {3, 6, 7, 11};
    int h = 8;
    cout << sol.minEatingSpeed(piles, h);

    return 0;
}