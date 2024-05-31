class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = n / 2;

        // Function to count vowels in a given string segment
        auto countVowels = [](const string& str, int start, int end) -> int {
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int count = 0;
            for (int i = start; i < end; ++i) {
                if (vowels.count(str[i])) {
                    ++count;
                }
            }
            return count;
        };

        int vowelsInFirstHalf = countVowels(s, 0, mid);
        int vowelsInSecondHalf = countVowels(s, mid, n);

        return vowelsInFirstHalf == vowelsInSecondHalf;
    }
};