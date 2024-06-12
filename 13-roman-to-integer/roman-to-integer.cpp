class Solution {
public:
    int romanToInt(string s) {
        // Define the values for each Roman numeral character
    std::unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    int prevValue = 0;

    // Iterate through the string from right to left
    for (int i = s.length() - 1; i >= 0; --i) {
        int currentValue = roman[s[i]];

        // If the current value is less than the previous value, subtract it
        if (currentValue < prevValue) {
            total -= currentValue;
        } else {
            // Otherwise, add it to the total
            total += currentValue;
        }

        // Update the previous value
        prevValue = currentValue;
    }

    return total;
    }
};