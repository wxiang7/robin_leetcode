class Solution { 
private: 
    typedef const char* ccptr; 
    typedef tuple<ccptr, ccptr, ccptr> tuple_ccptr; 
    map<tuple_ccptr, bool> inter; 
 
 
    bool interleave(const char* s1, const char *s2, const char *s3) {         
        tuple_ccptr key = make_tuple(s1, s2, s3); 
        map<tuple_ccptr, bool>::iterator it = inter.find(key); 
        if (it != inter.end()) return it->second; 
         
        if (*s1 == 0 && *s2 == 0 && *s3 == 0) { 
            inter[key] = true; 
            return true; 
        } else { 
            if (*s1 == *s3 && interleave(s1+1, s2, s3+1)) { 
                inter[key] = true; 
                return true; 
            } 
            if (*s2 == *s3 && interleave(s1, s2+1, s3+1)) { 
                inter[key] = true; 
                return true; 
            } 
            inter[key] = false; 
            return false; 
        } 
    } 
 
 
public: 
    bool isInterleave(string s1, string s2, string s3) { 
        if (s1.length() + s2.length() != s3.length()) return false; 
        inter.clear(); 
        return interleave(s1.c_str(), s2.c_str(), s3.c_str()); 
    } 
};