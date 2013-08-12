class Solution { 
    inline ushort min(ushort a, ushort b) { 
        return a < b ? a : b; 
    } 
     
public: 
    int minCut(string s) { 
        if (s.length() <= 1) return 0; 
        int slen = s.length(); 
        const char* t = s.c_str(); 
        vector<vector<bool> > is_palindrome(slen, vector<bool>(slen+1, 0)); 
        for (int i = 0; i < slen; ++i) { 
            is_palindrome[i][0] = true; 
            is_palindrome[i][1] = true; 
        } 
        vector<ushort> min_cut(slen, 0); 
         
        for (int p = 1; p < slen; ++p) { 
            min_cut[p] = p; 
            for (int flen = 0; flen <= p; ++flen) { 
                if (flen < p) { 
                    is_palindrome[flen][p+1-flen] =  
                        t[flen] == t[p] && is_palindrome[flen+1][p-flen-1];   
                } 
                if (is_palindrome[flen][p+1-flen]) { 
                    min_cut[p] = min(min_cut[p],  
                                     flen == 0 ? 0 : min_cut[flen-1] + 1); 
                } 
            } 
        } 
         
        return min_cut[slen-1]; 
    } 
};