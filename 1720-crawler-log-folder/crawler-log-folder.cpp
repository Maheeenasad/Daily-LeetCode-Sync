class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        
        for (const string& log : logs) {
            if (log == "../") {
                if (depth > 0) {
                    depth--;
                }
            } else if (log == "./") {
                // Do nothing
            } else {
                // This is a move to a subdirectory (like "x/")
                depth++;
            }
        }
        
        return depth;  
    }
};