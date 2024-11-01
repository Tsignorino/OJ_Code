#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceTraveled_1(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            ans += 50;
            if (additionalTank) {
                additionalTank--;
                mainTank++;
            }
        }
        return ans + mainTank * 10;
    }

public:
    int distanceTraveled_2(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5) {
            int div = mainTank / 5;
            ans += div * 50;
            mainTank %= 5;
            // div = min(div, additionalTank);
            // additionalTank -= div;
            // mainTank += div;
            mainTank += min(additionalTank, div);
            additionalTank = max(additionalTank - div, 0);
        }
        return ans + mainTank * 10;
    }

public:
    int distanceTraveled_3(int mainTank, int additionalTank) {
        // 考虑能从副油箱获得多少燃料
        return (mainTank + min((mainTank - 1) / 4, additionalTank)) * 10;
    }
};

class mySolution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank) {
            int div = mainTank / 5, mod = mainTank % 5;
            ans += div * 5 * 10;
            mainTank = mod;

            mainTank += min(additionalTank, div);
            additionalTank = max(additionalTank - div, 0);

            if (mainTank == mod) {
                ans += mainTank * 10;
                break;
            }
        }
        return ans;
    }
};