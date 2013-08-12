class Solution { 
public: 
    string multiply(string num1, string num2) { 
        unsigned char* result = new unsigned char[num1.size() + num2.size() + 1]; 
        memset(result, 0, sizeof(unsigned char) * (num1.size() + num2.size() + 1)); 
        int num_len1 = num1.size() 
          , num_len2 = num2.size() 
          , highest = num_len1; 
        for (int i = num_len2 - 1; i >= 0; --i) { 
            unsigned char digit2 = num2[i] - '0'; 
            for (int j = num_len1 - 1; j >= 0; --j) { 
                unsigned char digit1 = num1[j] - '0'; 
                result[(num_len2 - i - 1) + (num_len1 - j - 1)] += digit1 * digit2; 
            } 
            highest = max(highest, num_len2-i-1 + num_len1); 
            for (int j = 0; j < highest; ++j) { 
                if (result[j] >= 10) { 
                    result[j+1] += result[j] / 10; 
                    result[j] = result[j] % 10; 
                    if (j == highest-1) { 
                        ++highest; 
                    } 
                } 
            } 
        } 
        while (highest > 1 && result[highest-1] == 0) --highest; 
        string ret; 
        for (int i = 0; i < highest; ++i) 
            ret = char(result[i] + '0') + ret; 
        delete[] result; 
        return ret; 
    } 
}; 
 