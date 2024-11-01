#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> set {'a', 'e', 'i', 'o', 'u'};
        for (char ch : s) {
            if (set.contains(ch)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}