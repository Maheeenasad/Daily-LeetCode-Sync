class Solution {
public:
    string countOfAtoms(string formula) {
         int n = formula.size();
        stack<unordered_map<string, int>> stk;
        unordered_map<string, int> current;
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                // Push current map to stack and start a new scope
                stk.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                // Compute multiplier after ')'
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = start == i ? 1 : stoi(formula.substr(start, i - start));
                
                // Pop the top map from stack and merge
                if (!stk.empty()) {
                    auto prev = stk.top(); stk.pop();
                    for (const auto& p : current) {
                        prev[p.first] += p.second * multiplier;
                    }
                    current = prev;
                }
            } else {
                // Parse element name
                int start = i;
                i++; // Move past first uppercase letter
                while (i < n && islower(formula[i])) i++; // Move past lowercase letters
                
                string element = formula.substr(start, i - start);
                
                // Parse digit
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = start == i ? 1 : stoi(formula.substr(start, i - start));
                
                current[element] += count;
            }
        }
        
        // Convert final counts to required output format
        map<string, int> sortedCounts(current.begin(), current.end());
        string result;
        for (const auto& p : sortedCounts) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        
        return result;
    }
};