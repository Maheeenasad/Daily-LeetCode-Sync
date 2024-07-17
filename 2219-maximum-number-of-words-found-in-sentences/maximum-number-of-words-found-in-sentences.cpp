class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
         int maxWords = 0;
        
        for (const string& sentence : sentences) {
            // Count the number of words in the current sentence
            int wordCount = 1;
            for (char c : sentence) {
                if (c == ' ') {
                    wordCount++;
                }
            }
            // Update maxWords if current sentence has more words
            maxWords = max(maxWords, wordCount);
        }
        
        return maxWords; 
    }
};