#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double d = 1 - discount / 100.0;

        stringstream ss(sentence);
        string ans, s;
        while (ss >> s) {
            if (!ans.empty()) {
                ans += ' ';
            }

            if (s.size() > 1 && s[0] == '$' && all_of(s.begin() + 1, s.end(), ::isdigit)) {
                stringstream tmp;
                tmp << fixed << setprecision(2) << '$' << stoll(s.substr(1)) * d;
                ans += tmp.str();
            } else {
                ans += s;
            }
        }
        return ans;
    }
};

/*
Python:
class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        d = 1 - discount / 100
        a = sentence.split(' ')
        for i, w in enumerate(a):
            if w[0] == '$' and w[1:].isdigit():
                a[i] = f"${int(w[1:]) * d :.2f}"
        return ' '.join(a)
*/

int main() {
    Solution sol;

    return 0;
}