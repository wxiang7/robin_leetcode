class Solution { 
public: 
    bool isNumber(const char *s) { 
        int ptr = 0 
          , mid = 0 
          , exp = 0 
          , pre = 0; 
         
        while (s[ptr] == ' ') ++ptr; 
         
        if (s[ptr] == 0) return false; 
        // check +/- 
        if (s[ptr] == '-' || s[ptr] == '+') ++ptr; 
         
        while (s[ptr] >= '0' && s[ptr] <= '9') { 
            ++ptr; 
            ++pre; 
        } 
         
        if (s[ptr] != '.' && pre == 0) { 
            return false; 
        } else if (s[ptr] == '.') { 
            ++ptr; 
            goto check_mid; 
        } else { 
            if (s[ptr] == 0) return true; 
            else if (s[ptr] == 'e' || s[ptr] == 'E') { 
                ++ptr; 
                goto check_exp; 
            } 
        } 
         
        check_mid: 
            while (s[ptr] >= '0' && s[ptr] <= '9') { 
                ++ptr; 
                ++mid; 
            } 
            if (s[ptr] == 0) return pre > 0 || mid > 0; 
            if (pre == 0 && mid == 0) return false; 
            if (s[ptr] == 'e' || s[ptr] == 'E') { 
                ++ptr; 
                goto check_exp; 
            } else { 
                // skip spaces 
                while (s[ptr] == ' ') ++ptr; 
                return s[ptr] == 0; 
            } 
             
        check_exp: 
            if (s[ptr] == '-' || s[ptr] == '+') ++ptr; 
            while (s[ptr] >= '0' && s[ptr] <= '9') { 
                ++ptr; 
                ++exp; 
            } 
            // skip spaces 
            while (s[ptr] == ' ') ++ptr; 
            if (s[ptr] != 0 || exp == 0) return false; 
        return true; 
    } 
}; 