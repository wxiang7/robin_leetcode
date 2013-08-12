class Solution { 
public: 
    string getPermutation(int n, int k) { 
        int base = 1; 
        for (int i = 1; i < n; ++i) base *= i; 
        vector<int> seq(n, 0); 
        vector<bool> taken(n, false); 
        k -= 1; 
        for (int i = n-1; i > 0; --i) { 
            seq[i] = k / base; 
            k %= base; 
            base /= i; 
        } 
        ostringstream buf; 
        for (int i = n-1; i > 0; --i) { 
            int next = -1, count = 0; 
            while (taken[next+1]) ++next; 
            do { 
                ++next; 
                count += taken[next] ?  0 : 1; 
            } while (count <= seq[i]); 
            taken[next] = true; 
            buf << char(next + '1'); 
        } 
        for (int i = 0; i < n; ++i) { 
            if (!taken[i]) { 
                buf << char(i + '1'); 
                break; 
            } 
        } 
        return buf.str(); 
    } 
}; 