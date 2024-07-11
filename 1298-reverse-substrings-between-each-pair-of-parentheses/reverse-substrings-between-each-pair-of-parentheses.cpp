class Solution {
public:
    string reverseParentheses(string s) {
          std::stack<char> st;
        
        for (char ch : s) {
            if (ch == ')') {
                // Collect characters inside the parentheses
                std::string temp;
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                // Pop the opening '('
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                // Push the reversed string back to the stack
                for (char c : temp) {
                    st.push(c);
                }
            } else {
                st.push(ch);
            }
        }
        
        // Collect the result from the stack
        std::string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};