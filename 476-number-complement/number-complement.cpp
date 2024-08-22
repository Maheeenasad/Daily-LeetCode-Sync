class Solution {
public:
    int findComplement(int num) {
       // Edge case: when num is 0, its complement should be 1
        if (num == 0) return 1;

        // Calculate the mask which has all bits set to 1 with the same bit length as num
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;

        // XOR num with the inverted mask to get the complement
        return ~num & ~mask;
    }
};