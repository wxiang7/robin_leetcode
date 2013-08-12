class Solution {
public:
    int atoi(const char *str) {
        int minus = 1, valid = 0;
        bool begin = false;
        unsigned int result = 0;
        while(*str) {
            if (*str >= '0' && *str <='9') {
                if (begin) {
                    if ((*str >= '8' && result >= 214748364) || valid == 10)
                        return minus < 0 ? -2147483648 : 2147483647;
                    result = result*10 + (*str-'0');
                } else {
                    begin = true;
                    result = *str - '0';
                }
                valid++;
            } else if (*str == '+' || *str == '-') {
                if (begin) {
                    break;
                } else {
                    begin = true;
                    minus = *str == '-' ? -1 : 1;
                }
            } else if ((*str != ' ' && *str != '\t') || begin) {
                break;
            }
            str++;
        }
        return minus*result;
    }
};