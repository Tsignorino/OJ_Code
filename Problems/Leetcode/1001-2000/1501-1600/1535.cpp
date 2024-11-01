#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = arr[0], cnt = 0;
        for (int i = 1; i < arr.size() && cnt < k; ++i) {
            if (arr[i] > mx) {
                mx = arr[i];
                cnt = 0;
            }
            cnt++;
        }
        return mx;
    }
};

int main() {
    Solution sol;

    return 0;
}