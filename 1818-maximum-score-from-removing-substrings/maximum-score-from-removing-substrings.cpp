class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper function to remove substring and calculate points
        auto removeAndScore = [](string &s, char first, char second, int points) {
            stack<char> st;
            int score = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    score += points;
                } else {
                    st.push(c);
                }
            }
            // Reconstruct the string from the stack
            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return make_pair(remaining, score);
        };
        
        int totalScore = 0;
        if (x >= y) {
            // Remove "ab" first
            auto [remaining, score] = removeAndScore(s, 'a', 'b', x);
            totalScore += score;
            // Then remove "ba"
            tie(remaining, score) = removeAndScore(remaining, 'b', 'a', y);
            totalScore += score;
        } else {
            // Remove "ba" first
            auto [remaining, score] = removeAndScore(s, 'b', 'a', y);
            totalScore += score;
            // Then remove "ab"
            tie(remaining, score) = removeAndScore(remaining, 'a', 'b', x);
            totalScore += score;
        }
        
        return totalScore; 
    }
};