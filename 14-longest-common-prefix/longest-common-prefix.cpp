class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       
    if (strs.empty()) {
        return "";
    }

    std::string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i) {
        const std::string& currentStr = strs[i];
        int j = 0;

        // Compare prefix with the current string
        while (j < prefix.size() && j < currentStr.size() && prefix[j] == currentStr[j]) {
            j++;
        }

        // Update the prefix to the matched portion
        prefix = prefix.substr(0, j);

        // If the prefix is empty, there is no common prefix
        if (prefix.empty()) {
            return "";
        }
    }

    return prefix;

    }
};