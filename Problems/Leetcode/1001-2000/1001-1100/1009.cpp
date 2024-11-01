#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution { //* [0, 10^9)
public:
    int bitwiseComplement(int num) {
        int high = 0;
        for (int i = 1; i <= 30; ++i) {
            if (num >= (1 << i)) {
                high = i;
            } else {
                break;
            }
        }
        int mask = high == 30 ? 0x7fffffff : (1 << (high + 1)) - 1;
        return num ^ mask;
    }
};