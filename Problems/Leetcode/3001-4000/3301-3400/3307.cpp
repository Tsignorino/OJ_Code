#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;

        int d = 0;
        for (int i = bit_width(k * 1ull) - 1; i >= 0; --i) {
            if (k >> i & 1) {
                d += operations[i];
            }
        }
        return 'a' + d % 26;
    }
};

int main() {
    Solution sol;

    // vector<int> operations {0, 1, 0, 1};
    // cout << sol.kthCharacter(10, operations);

    vector<int> operations {0, 0, 0};
    cout << sol.kthCharacter(5, operations);

    return 0;
}