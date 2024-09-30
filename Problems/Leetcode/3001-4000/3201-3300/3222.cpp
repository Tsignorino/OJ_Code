#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) { return min(x, y / 4) & 1 ? "Alice" : "Bob"; }
};

int main() {
    Solution sol;

    return 0;
}