#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();
        ranges::sort(capacity, greater<int>());
        int sum = accumulate(apple.begin(), apple.end(), 0);
        for (int i = 0; i < n; ++i) {
            sum -= capacity[i];
            if (sum <= 0) {
                return i + 1;
            }
        }
        return -1;
    }
};

/*
from typing import List

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        s = sum(apple)
        capacity.sort(reverse=True)
        for i, x in enumerate(capacity, 1):
            s -= x
            if s <= 0:
                return i
        return -1
*/