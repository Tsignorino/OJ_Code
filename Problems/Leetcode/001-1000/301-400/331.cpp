#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        int slots = 1;
        while (i < n) {
            if (slots == 0) {
                return false;
            }

            if (preorder[i] == ',') {
                i++;
            } else if (preorder[i] == '#') {
                slots--;
                i++;
            } else {
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                slots++; // slots = slots - 1 + 2;
            }
        }
        return slots == 0;
    }
};