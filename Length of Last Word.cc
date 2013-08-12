class Solution { 
public: 
    int lengthOfLastWord(const char *s) { 
        int len = strlen(s), count = 0; 
        int ptr = len - 1; 
        bool started = false; 
         
        while (ptr >= 0) { 
            char ch = s[ptr]; 
            if (!started) { 
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) { 
                    started = true; 
                    count = 1; 
                } 
            } else { 
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) { 
                    ++count; 
                } else { 
                    break; 
                } 
            } 
            --ptr; 
        } 
         
        return count; 
    } 
};