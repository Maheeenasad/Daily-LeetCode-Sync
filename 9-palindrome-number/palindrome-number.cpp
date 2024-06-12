class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes

    if (x < 0) {

        return false;

    }

    

    // Calculate the reverse of the number

    int original = x;

    long reversed = 0; // Use long to prevent overflow

    

    while (x != 0) {

        reversed = reversed * 10 + x % 10;

        x /= 10;

    }

    

    // Check if the original number is equal to its reverse

    return original == reversed;
    }
};