class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -2147483648)
            return 1;
        else if (dividend == -2147483648 && divisor > 0)
            return -1 - divide(-(dividend + divisor), divisor);
        else if (dividend == -2147483648 && divisor < 0)
            return - divide(dividend, -divisor);
            
        if (dividend == 0 || divisor == -2147483648)
            return 0;
            
        if (dividend < 0 != divisor < 0)
            return -divide(std::abs(dividend), std::abs(divisor));
        if (dividend < 0 || divisor < 0)
            return divide(std::abs(dividend), std::abs(divisor));
            
        int last = divisor, current;
        int counter = 1;
        if (dividend < last)
            return 0;
        
        current = last + last;
        while (dividend >= current && last < 1073741824) {
            last = current;            
            current = last + last;
            counter <<= 1;
        }
        
        int remain = dividend - last;
        return counter + divide(remain, divisor);
    }
};