typedef unsigned short usht; 
typedef tuple<usht, usht, usht> status_idx; 
 
namespace std { 
    template <> 
    struct hash<status_idx> { 
        size_t operator() (status_idx tp) const { 
            return get<0>(tp)*dim2_ + get<1>(tp)*dim1_ + get<2>(tp); 
        } 
         
        hash<status_idx>(int dim1) : dim1_(dim1), dim2_(dim1*dim1) {} 
         
        private: 
            unsigned int dim1_; 
            unsigned int dim2_; 
    }; 
} 
 
class Solution {   
private:       
    unordered_map<status_idx, bool> *status;   
    const char* s1;   
    const char* s2;   
   
    bool isScramble(usht p1, usht p2, usht len) {   
        status_idx idx = make_tuple(p1, p2, len);   
        auto it = status->find(idx);   
        if (it == status->end()) {   
            bool res = false;   
            if (len == 1) {   
                res = s1[p1] == s2[p2];   
            } else {   
                for (usht sub_len = 1; sub_len < len; ++sub_len) {   
                    usht other_len = len - sub_len;   
                    res = isScramble(p1, p2, sub_len)   
                         && isScramble(p1+sub_len, p2+sub_len, other_len);   
                    if (res) break;   
                    res = isScramble(p1, p2+other_len, sub_len)   
                         && isScramble(p1+sub_len, p2, other_len);   
                    if (res) break;   
                }   
            }   
            status->insert(make_pair(idx, res));   
            return res;   
        } else {   
            return it->second;   
        }   
    }   
      
public:   
    bool isScramble(string str1, string str2) {   
        usht l1 = static_cast<usht>(str1.length());   
        usht l2 = static_cast<usht>(str2.length());   
        if (l1 != l2) return false;   
        if (l1 == 0) return true;   
        status = new unordered_map<status_idx, bool>(l1*l1*l1, std::hash<status_idx>(l1)); 
        s1 = str1.c_str();   
        s2 = str2.c_str();   
        bool ret = isScramble(0, 0, l1); 
        delete status; 
        return  ret; 
    }   
}; 