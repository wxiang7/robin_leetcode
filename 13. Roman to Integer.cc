class Solution {
public:
    int digit(const string& s, int* pos, char* sym) {
        int first_count = 0;
        if (s[*pos] == sym[0] || s[*pos] == sym[1]) {
            char first = s[*pos];
            if (first == sym[0] && *pos < s.length()-1 && s[(*pos)+1] == sym[2]) {
                *pos += 2;
                return 9;
            } else if (first == sym[0] && *pos < s.length()-1 && s[(*pos)+1] == sym[1]) {
                *pos += 2;
                return 4;
            } else if (first == sym[0]) {
                first_count = 1;
                *pos += 1;
                if (*pos < s.length() && s[*pos] == sym[0]) {
                    *pos += 1;
                    first_count += 1;
                }
                if (*pos < s.length() && s[*pos] == sym[0]) {
                    *pos += 1;
                    first_count += 1;
                }
                return first_count;
            } else if (first == sym[1]) {
                first_count = 5;
                *pos += 1;
                if (*pos < s.length() && s[*pos] == sym[0]) {
                    *pos += 1;
                    first_count += 1;
                }
                if (*pos < s.length() && s[*pos] == sym[0]) {
                    *pos += 1;
                    first_count += 1;
                }
                if (*pos < s.length() && s[*pos] == sym[0]) {
                    *pos += 1;
                    first_count += 1;
                }
                return first_count;
            }
        } else {
            return 0;
        }
    }
    
    int romanToInt(string s) {
        int pos = 0;
        int kilo = digit(s, &pos, "M  ");
        int hund = digit(s, &pos, "CDM");
        int deca = digit(s, &pos, "XLC");
        int deci = digit(s, &pos, "IVX");
        return kilo*1000 + hund*100 + deca*10 + deci;
    }
};