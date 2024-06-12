class Solution {
public:
    string addBinary(string a, string b) {
        std::string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0'; // Convert character to integer
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0'; // Convert character to integer
            j--;
        }

        // Add current digit to result (0 or 1)
        result += (sum % 2) + '0';

        // Calculate new carry (0 or 1)
        carry = sum / 2;
    }

    // Since we built the result string from the least significant digit to most,
    // we need to reverse it before returning.
    std::reverse(result.begin(), result.end());

    return result;

    }
};