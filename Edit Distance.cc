class Solution { 
public: 
    inline unsigned short min(unsigned int a, unsigned int b) { 
        return a < b ? a : b; 
    } 
     
    int minDistance(string word1, string word2) { 
        int tlen = word2.length(); 
        int slen = word1.length(); 
        if (slen == 0 || tlen == 0) return max(slen, tlen); 
        int slen1 = slen+1, tlen1 = tlen+1; 
        unsigned short *dist = new unsigned short[slen1*tlen1]; 
        int *src = new int[slen1]; 
        int *tgt = new int[tlen1]; 
        memset(dist, 0, sizeof(unsigned short)*slen1*tlen1); 
        memset(src, 0, sizeof(int)*slen1); 
        memset(tgt, 0, sizeof(int)*tlen1); 
        for (int i = 0; i < slen1; ++i) dist[i] = i; 
        for (int i = 0; i < tlen1; ++i) dist[i*slen1] = i; 
         
        int res = numeric_limits<int>::max(); 
        for (int t = 1; t < tlen1; ++t) { 
            for (int s = 1; s < slen1; ++s) { 
                unsigned short& calc = dist[t*slen1+s]; 
                calc = (word1[s-1] == word2[t-1] ? 0 : 1) + 
                       dist[(t-1)*slen1+s-1]; 
                for (int i = s-1; i >= 0; --i) { 
                    calc = min(calc, s-i + dist[t*slen1+i]); 
                    if (s + tgt[t] >= calc) break; 
                } 
                for (int i = t-1; i >= 0; --i) { 
                    calc = min(calc, t-i + dist[i*slen1+s]); 
                    if (t + src[s] >= calc) break; 
                } 
                if (t == tlen) res = min(res, calc+slen-s); 
                tgt[t] = min((int)calc-s, tgt[t]); 
                src[s] = min((int)calc-t, src[s]); 
            } 
        } 
         
        delete[] dist; 
        delete[] src; 
        delete[] tgt; 
        return res; 
    } 
}; 