class Solution {
public:
    string numberToWords(int num) {
         if (num == 0) return "Zero";
        
        return intToString(num).substr(1); 
    }
    private:
    std::vector<std::string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::vector<std::string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::vector<std::string> thousands = {"", "Thousand", "Million", "Billion"};

    std::string intToString(int num) {
        if (num == 0) return "";
        else if (num < 20) return " " + lessThan20[num];
        else if (num < 100) return " " + tens[num / 10] + intToString(num % 10);
        else if (num < 1000) return " " + lessThan20[num / 100] + " Hundred" + intToString(num % 100);
        else {
            for (int i = 1; i < thousands.size(); ++i) {
                if (num < pow(1000, i + 1)) {
                    return intToString(num / pow(1000, i)) + " " + thousands[i] + intToString(num % int(pow(1000, i)));
                }
            }
        }
        return "";
    }

};