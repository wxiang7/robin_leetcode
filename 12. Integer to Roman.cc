class Solution {
public:
    void duplicate(char sym, int count, string* result) {
        while ((count--) > 0) {
            result->push_back(sym);
        }
    }
    
    void single(int digit, char* roman, string* result) {
        if (digit == 0) {
            return;
        } else if (digit <= 3) {
            duplicate(roman[0], digit, result);    
        } else if (digit == 4) {
            result->push_back(roman[0]);
            result->push_back(roman[1]);
        } else if (digit < 9) {
            result->push_back(roman[1]);
            duplicate(roman[0], digit-5, result);
        } else {
            result->push_back(roman[0]);
            result->push_back(roman[2]);
        }
    }
    
    string intToRoman(int num) {
        string builder;
        single(num/1000, "M", &builder); num %= 1000;
        single(num/100, "CDM", &builder); num %= 100;
        single(num/10, "XLC", &builder); num %= 10;
        single(num, "IVX", &builder);
        return builder;
    }
};