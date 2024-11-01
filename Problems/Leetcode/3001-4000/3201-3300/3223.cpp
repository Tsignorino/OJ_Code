#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        map<char, int> map;
        for (char ch : s) {
            map[ch]++;
        }

        int ans = map.size();
        for (auto& [_, v] : map) {
            if (v % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}