class Solution {
public:
    int findPermutationDifference(string s, string t) {
          int n = s.length();
        int difference = 0;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int indexInT = t.find(c);
            difference += abs(i - indexInT);
        }

        return difference;
    }
};