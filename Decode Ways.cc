class Solution { 
public: 
    int numDecodings(string s) { 
        if (s.length() == 0) return 0; 
        int slen = s.length(); 
        int *decodes = new int[slen+1]; 
         
        memset(decodes, 0, (slen+1)*sizeof(int)); 
        decodes[slen] = 1; 
        for (int i = slen-1; i >= 0; --i) { 
            if (i != slen-1 &&  
               (s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] < '7'))) { 
                decodes[i] += decodes[i+2];   
            } 
            if (s[i] > '0') { 
                decodes[i] += decodes[i+1]; 
            } 
        } 
         
        int res = decodes[0]; 
        delete[] decodes; 
        return res; 
    } 
}; 