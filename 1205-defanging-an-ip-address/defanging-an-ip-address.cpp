class Solution {
public:
    string defangIPaddr(string address) {
         string defanged = "";
        for (char c : address) {
            if (c == '.') {
                defanged += "[.]";
            } else {
                defanged += c;
            }
        }
        return defanged; 
    }
};