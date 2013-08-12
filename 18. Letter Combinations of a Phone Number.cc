class Solution {
public:
    void enumerate(const char* digits, string* syms, string cur, 
        vector<string>* result) {
        if (*digits == 0) {
            result->push_back(cur);
        } else {
            for(const auto& ch : syms[*digits-'0']) {
                cur.push_back(ch);
                enumerate(digits+1, syms, cur, result);
                cur.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string syms[] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ret;
        enumerate(digits.c_str(), syms, "", &ret);
        return ret;
    }
};