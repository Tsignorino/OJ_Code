#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        string s("@#$");
        string t("aeiou");
        int flag = 0;
        for (char& ch : word) {
            //-- !isdigit(ch) && !islower(ch) && !isupper(ch)
            if (find(s.begin(), s.end(), ch) != s.end()) {
                return false;
            }
            if (isdigit(ch)) {
                continue;
            }

            ch = tolower(ch);
            if (find(t.begin(), t.end(), ch) != t.end()) {
                flag |= 1;
            } else {
                flag |= 2;
            }
        }
        return flag == 3;
    }
};

int main() {
    Solution sol;

    string word("234Adas");
    sol.isValid(word);

    return 0;
}