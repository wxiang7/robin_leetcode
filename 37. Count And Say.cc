class Solution {
public:
    string next(string& n) {
        string ret;
        char last = n[0];
        int ptr = 1
          , count = 1;
        while (ptr < n.length()) {
            char current = n[ptr++];
            if (current != last) {
                ret += std::to_string(count);
                ret += last;
                last = current;
                count = 1;
            } else {
                ++count;
            }
        }
        ret += std::to_string(count);
        ret += last;
        return ret;
    }
    
    string countAndSay(int n) {
        string ret = "1";
        while (--n > 0) {
            ret = next(ret);
        }
        return ret;
    }
};
