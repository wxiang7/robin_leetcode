class Solution { 
public: 
    bool canJump(int A[], int n) { 
        if (n <= 1) return true; 
        bool* reachable = new bool[n]; 
        memset(reachable, 0, n); 
         
        reachable[0] = true; 
        for (int i = 1; i < n; ++i) { 
            for (int j = i-1; j >= 0; --j) 
                if (reachable[j] && A[j] >= i-j) { 
                    reachable[i] = true; 
                    break; 
                } 
        } 
         
        bool ret = reachable[n-1]; 
        delete[] reachable; 
        return ret; 
    } 
};