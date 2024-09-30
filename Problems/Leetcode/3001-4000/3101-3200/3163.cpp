#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string compressedString(string word) {
        string ans;
        int pre = -1;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (i + 1 == word.size() || ch != word[i + 1]) {
                int k = i - pre;
                for (int j = 0; j < k / 9; ++j) {
                    ans += '9';
                    ans += ch;
                }
                if (k % 9) {
                    ans += k % 9 + '0';
                    ans += ch;
                }
                pre = i;
            }
        }
        return ans;
    }
};

class mySolution {
public:
    string compressedString(string word) {
        char ch = word[0];
        int res = 0;
        string ans;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                if (++res == 9) {
                    ans += '9';
                    ans += ch;
                    res = 0;
                }
            } else {
                if (res > 0) {
                    ans += res + '0';
                    ans += ch;
                }
                ch = word[i];
                res = 1;
            }
        }

        if (res > 0) {
            ans += res + '0';
            ans += ch;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}