class Solution { 
public: 
    string addBinary(string a, string b) { 
        int la = a.length(), lb = b.length(), lc = std::max(la, lb) + 2; 
        char* c = new char[lc]; 
         
        memset(c, 0, sizeof(char)*lc); 
        for (int i = 0; i < std::max(la, lb); ++i) { 
            if (i < la) c[i] += a[la-i-1]-'0'; 
            if (i < lb) c[i] += b[lb-i-1]-'0'; 
        } 
         
        int upper = std::max(la, lb)-1, ptr = 0; 
        while (ptr <= upper) { 
            c[ptr+1] += c[ptr] >> 1; 
            c[ptr] %= 2; 
            if (ptr == upper && c[upper+1] > 0) ++upper; 
            ++ptr; 
        } 
         
        while (c[upper] == 0 && upper > 0) --upper; 
         
        string res; 
        for (int i = 0; i <= upper; ++i) 
            res = char(c[i]+'0') + res; 
         
        delete[] c; 
        return res; 
    } 
}; 