#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int sum = numBottles;
        while (numBottles >= numExchange) {
            sum++;
            numBottles -= numExchange;
            numBottles++, numExchange++;
        }
        return sum;
    }
};