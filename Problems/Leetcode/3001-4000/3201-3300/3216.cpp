#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] % 2 == s[i - 1] % 2 && s[i] < s[i - 1]) {
                swap(s[i], s[i - 1]);
                break;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    return 0;
}