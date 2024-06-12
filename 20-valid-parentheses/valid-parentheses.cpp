class Solution {
public:
    bool isValid(string s) {
        // Map to match closing brackets to their corresponding opening brackets
    std::unordered_map<char, char> bracketPairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    // Stack to keep track of opening brackets
    std::stack<char> stack;

    for (char ch : s) {
        // If it's a closing bracket
        if (bracketPairs.find(ch) != bracketPairs.end()) {
            // Check if the stack is not empty and the top element is the corresponding opening bracket
            if (!stack.empty() && stack.top() == bracketPairs[ch]) {
                stack.pop();
            } else {
                // If no matching opening bracket, return false
                return false;
            }
        } else {
            // If it's an opening bracket, push it onto the stack
            stack.push(ch);
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return stack.empty();
    }
};