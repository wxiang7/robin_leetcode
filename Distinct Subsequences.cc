class Solution { 
public: 
    int numDistinct(string S, string T) { 
        int slen = S.length(); 
        int tlen = T.length(); 
        if (slen == 0 || tlen == 0) return 0; 
        vector<vector<int> > distinct(tlen, vector<int>(slen, 0)); 
        unordered_map<char, vector<short> > pos; 
        for (int i = 0; i < slen; ++i) pos[S[i]].push_back(i); 
        for (int t = 0; t < tlen; ++t) { 
            vector<short>& ch_pos = pos[T[t]]; 
            for (int s = 0; s < slen; ++s) { 
                int& dis = distinct[t][s]; 
                for (short c_pos : ch_pos) { 
                    if (c_pos > s) break; 
                    if (t == 0) { 
                        dis += 1;  
                    } else if (c_pos > 0) { 
                        dis += distinct[t-1][c_pos-1]; 
                    } 
                } 
            } 
        } 
        return distinct[tlen-1][slen-1]; 
    } 
}; 