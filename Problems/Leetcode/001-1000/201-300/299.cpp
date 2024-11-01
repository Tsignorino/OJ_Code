#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int cntA = 0, cntB = 0;
        int cntS[10] {}, cntG[10] {};
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                cntA++;
            } else {
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; ++i) {
            cntB += min(cntS[i], cntG[i]);
        }

        return to_string(cntA) + 'A' + to_string(cntB) + 'B';
    }
};

int main() {
    string secret("1123"), guess("0111");

    Solution sol;
    cout << sol.getHint(secret, guess);

    return 0;
}