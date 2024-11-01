#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int id = binary.find('0');
        if (id == string::npos) {
            return binary;
        }

        int n = binary.size();
        int cnt = count(binary.begin() + id, binary.end(), '1');
        return string(n - 1 - cnt, '1') + '0' + string(cnt, '1');
    }
};