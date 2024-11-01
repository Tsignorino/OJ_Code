#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    long long flowerGame(int n, int m) { return (ll) n * m / 2; }
};

int main() {
    Solution sol;

    int n = 3, m = 2;
    cout << sol.flowerGame(n, m);

    return 0;
}