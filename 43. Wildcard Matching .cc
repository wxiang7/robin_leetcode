// TLE solution 
class Solution { 
public: 
    bool isMatch(const char *s, const char *p) { 
       if (*s == 0 && *p == 0) { 
           return true; 
       } else if (*p == 0) { 
           return false; 
       } else if (*p == '?' && *s == 0) { 
           return false; 
       } else if (*p == '?') { 
           return isMatch(s+1, p+1); 
       } else if (*p == '*') { 
           bool result = false; 
           while (p[1] == '*') ++p; 
           while (*s != 0 && !result) { 
               result = isMatch(s++, p+1); 
           } 
  if (!result) 
               result = isMatch(s, p+1); 
           return result; 
       } else if (*p == *s) { 
           return isMatch(s+1, p+1); 
       } else { 
           return false; 
       } 
    } 
}; 
 
class Solution {  
public:  
    bool isMatch(const char *s, const char *p) {  
       int slen = strlen(s); 
       int plen = strlen(p); 
       bool *match[2]; 
       match[0] = new bool[slen+1]; 
       match[1] = new bool[slen+1]; 
       memset(match[0], 0, sizeof(bool)*(slen+1)); 
       memset(match[1], 0, sizeof(bool)*(slen+1)); 
        
       int left_star = -1; 
       if (p[0] == '*') { 
           left_star = 0; 
           while (p[left_star] == '*') ++left_star; 
       } 
        
       int *left = new int[plen]; 
       int *right = new int[plen]; 
       for (int i = 0, j = plen-1; i < plen; ++i, --j) { 
           left[i] = p[i] == '*' ? 0 : 1; 
           right[j] = p[j] == '*' ? 0 : 1; 
           if (i > 0) { 
               left[i] += left[i-1]; 
               right[j] += right[j+1]; 
           } 
       } 
        
       bool last = false, cur; 
       match[last][0] = true; 
       for (int y = 1; y <= plen; ++y) { 
           cur = !last; 
           int start = left[y-1]; 
           int end = min(slen-right[y-1]+1, slen); 
           memset(match[cur], 0, sizeof(bool)*(slen+1)); 
           for (int x = start; x <= end; ++x) { 
               if (x == 0) { 
                    match[cur][x] = p[y-1] == '*' && y <= left_star; 
               } else if (y > 0) { 
                   if (p[y-1] == '*') { 
                       if (y <= left_star) { 
                           match[cur][x] = true; 
                       } else { 
                           for (int k = x; k >= 0; --k) { 
                               if (match[cur][x] = match[last][k]) break; 
                           } 
                           while (p[y-1] == '*') ++y; 
                           --y; 
                       } 
                   } else if (p[y-1] == '?') { 
                       match[cur][x] = match[last][x-1]; 
                   } else { 
                       match[cur][x] = s[x-1] == p[y-1] && match[last][x-1]; 
                   } 
               } 
                
           }    
           last = cur; 
       } 
        
       bool res = match[last][slen]; 
       delete[] match[0]; 
       delete[] match[1]; 
       delete[] left; 
       delete[] right; 
       return res; 
    }  
}; 
