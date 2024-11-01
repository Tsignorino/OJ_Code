#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_prime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return n >= 2;
    }

public:
    int maximumPrimeDifference(vector<int>& nums) {
        int i = 0;
        while (!is_prime(nums[i])) {
            i++;
        }
        int j = nums.size() - 1;
        while (!is_prime(nums[j])) {
            j--;
        }
        return j - i;
    }
};

class mySolution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        function<bool(int)> is_prime = [](int n) -> bool {
            if (n == 1) {
                return false;
            }
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        };

        int id1 = -1, id2 = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (is_prime(nums[i])) {
                id1 = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (is_prime(nums[i])) {
                id2 = i;
                break;
            }
        }
        return id2 - id1;
    }
};