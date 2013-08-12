class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == 0 && *s == 0) {
            return true;
        } else if (*p == 0) {
            return false;
        } else if (*(p+1) == '*'&& *p != '.') {
            bool suffix = false;
            while (*s == *p && !suffix) {
                suffix |= isMatch(s, p+2);
                s++;
            }
            if (!suffix) {
                suffix |= isMatch(s, p+2);
            }
            return suffix;
        } else if (*(p+1) == '*'&& *p == '.') {
            bool suffix = false;
            while (*s != 0 && !suffix) {
                suffix |= isMatch(s, p+2);
                s++;
            }
            if (!suffix) {
                suffix |= isMatch(s, p+2);
            }
            return suffix;
        } else if (*p == '.' && *s == 0) {
            return false;
        } else if (*p == '.') {
            return isMatch(s+1, p+1);
        } else if (*s == *p) {
            return isMatch(s+1, p+1);
        } else {
            return false;
        }
        
    }
};