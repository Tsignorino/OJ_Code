#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int num = x;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return x % sum == 0 ? sum : -1;
    }
};