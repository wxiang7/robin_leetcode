class Solution { 
public: 
    string minWindow(string S, string T) { 
        int slen = S.length() 
          , tlen = T.length(); 
        if (slen == 0 || tlen == 0) return ""; 
         
        int char_size = numeric_limits<char>::max(); 
        bool *voc = new bool[char_size]; 
        int *count = new int[char_size]; 
        int voc_size = 0; 
        memset(count, 0, sizeof(int)*char_size); 
        memset(voc, 0, sizeof(bool)*char_size); 
        for (auto& ch : T) { 
            if (count[ch] == 0) ++voc_size; 
            voc[ch] = true; 
            ++count[ch]; 
        } 
         
        int from = 0 
          , end = -1 
          , okay_char_count = 0; 
        // seek to a candidate 
        do { 
            ++end; 
            --count[S[end]]; 
            if (count[S[end]] == 0) ++okay_char_count; 
        } while(end < slen && okay_char_count < voc_size); 
        if (okay_char_count < voc_size) return ""; 
         
        int min_len = end + 1 
          , min_from = 0; 
        while (end < slen) { 
           while (from < end) { 
               if (voc[S[from]] && count[S[from]] == 0) break; 
               ++count[S[from]]; 
               ++from; 
           } 
           if (min_len > end - from + 1) { 
               min_len = end - from + 1; 
               min_from = from; 
           } 
           if (end+1 < slen) { 
               --count[S[end+1]]; 
           } 
           ++end; 
        } 
         
        delete[] count; 
        delete[] voc; 
        return S.substr(min_from, min_len); 
    } 
};