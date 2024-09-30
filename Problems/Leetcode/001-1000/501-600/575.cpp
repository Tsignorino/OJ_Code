#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) { return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2); }
};

int main() {
    Solution sol;

    return 0;
}