#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findLUSlength(string a, string b) { return a == b ? -1 : max(a.size(), b.size()); }
};

int main() {
    Solution sol;

    return 0;
}