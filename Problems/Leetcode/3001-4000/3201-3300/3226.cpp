#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        if ((n ^ k) & k) { // or (n & k) != k
            return -1;
        }
        return __builtin_popcount(n ^ k); // or __builtin_popcount(n - k)
    }
};

int main() {
    Solution sol;

    return 0;
}