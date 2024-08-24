class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        vector<long long> candidates;
        
        // Edge cases: one more and one less digit
        candidates.push_back((long long)pow(10, len) + 1); // e.g. 1001 for 999
        candidates.push_back((long long)pow(10, len - 1) - 1); // e.g. 99 for 100

        // Generate the prefix
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        
        // Generate the palindrome by mirroring
        vector<long long> mirrors = {prefix - 1, prefix, prefix + 1};
        for (long long p : mirrors) {
            string s = to_string(p);
            string t = s + string(s.rbegin() + (len & 1), s.rend()); // create full palindrome
            candidates.push_back(stoll(t));
        }
        
        // Remove n itself from the candidates
        long long num = stoll(n);
        long long closest = -1;
        for (long long cand : candidates) {
            if (cand != num) {
                if (closest == -1 ||
                    abs(cand - num) < abs(closest - num) ||
                    (abs(cand - num) == abs(closest - num) && cand < closest)) {
                    closest = cand;
                }
            }
        }
        
        return to_string(closest);  
    }
};