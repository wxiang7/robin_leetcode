class Solution { 
public: 
    vector<int> plusOne(vector<int> &digits) { 
        std::reverse(digits.begin(), digits.end()); 
        int ptr = 0; 
        digits[0] += 1; 
        while (ptr < digits.size()) { 
            if (digits[ptr] < 10) break; 
            if (ptr == digits.size() - 1) digits.push_back(0); 
            digits[ptr+1] += digits[ptr] / 10; 
            digits[ptr] %= 10; 
            ++ptr; 
        } 
        std::reverse(digits.begin(), digits.end()); 
        return digits; 
    } 
};