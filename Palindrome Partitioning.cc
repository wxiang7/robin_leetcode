class Solution { 
private: 
    vector<vector<string> > res; 
    vector<string> current; 
     
    bool isPalindrome(const string& s) { 
        if (s.length() == 0) return true; 
        int from = 0 
          , to = s.length() - 1; 
        while (from < to) { 
            if (s[from] != s[to]) return false; 
            ++from; 
            --to; 
        } 
        return true; 
    } 
     
    void partition(const string& s, int pos) { 
        if (pos == s.length()) { 
            res.push_back(current); 
            return; 
        } 
        for (int len = 1; len <= s.length() - pos; ++len) { 
            string sub = s.substr(pos, len); 
            if (isPalindrome(sub)) { 
                current.push_back(sub); 
                partition(s, pos + len); 
                current.pop_back(); 
            } 
        } 
    } 
     
public: 
    vector<vector<string>> partition(string s) { 
        res.clear(); 
        current.clear(); 
        partition(s, 0); 
        return res; 
    } 
}; 