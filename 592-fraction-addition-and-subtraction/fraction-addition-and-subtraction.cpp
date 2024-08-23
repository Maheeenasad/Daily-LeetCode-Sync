class Solution {
public:
    string fractionAddition(string expression) {
           istringstream iss(expression);
        int A = 0, B = 1, a, b;
        char slash, sign;
        
        while (iss >> a >> slash >> b) {
            // Compute the numerator of the resulting fraction
            A = A * b + a * B;
            // Compute the denominator of the resulting fraction
            B *= b;
            // Simplify the fraction
            int gcd = abs(__gcd(A, B));
            A /= gcd;
            B /= gcd;
            // Read the sign for the next fraction (if any)
            iss >> sign;
            if (sign == '-') iss.putback(sign);
        }
        
        return to_string(A) + "/" + to_string(B);
    }
};