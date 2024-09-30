#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0, r = *max_element(quantities.begin(), quantities.end()) + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            int cnt = 0;
            for (const int& q : quantities) {
                cnt += (q - 1) / mid + 1;
            }

            if (cnt > n) {
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

    int n = 6;
    vector<int> quantities {11, 6};
    cout << sol.minimizedMaximum(n, quantities);

    return 0;
}