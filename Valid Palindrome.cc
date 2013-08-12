class Solution { 
public: 
    bool isPalindrome(string s) { 
        int slen = s.length(); 
        if (slen == 0) return true; 
        int from = 0 
          , to = slen-1; 
        while (from < to) { 
            if (!isalnum(s[from])) { 
                ++from; 
            } else if (!isalnum(s[to])) { 
                --to; 
            } else { 
                char first = s[from] 
                   , second = s[to]; 
                if (first >= 'A' && first <= 'Z') first = first - 'A' + 'a'; 
                if (second >= 'A' && second <= 'Z') second = second - 'A' + 'a'; 
                if (first != second) { 
                    return false; 
                } 
                ++from; 
                --to; 
            } 
        } 
        return true; 
    } 
}; 