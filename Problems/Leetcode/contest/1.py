class Solution:
    def smallestNumber(self, n: int) -> int:
        return (1 << n.bit_length()) - 1


""" 
C++:

class Solution {
public:
    int smallestNumber(int n) {
        return (1 << bit_width(n * 1ull)) - 1;
    }
};
"""
