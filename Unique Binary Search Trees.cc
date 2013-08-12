class Solution { 
public: 
    int numTrees(int n) { 
        int *num = new int[n+1]; 
        memset(num, 0, sizeof(int)*(n+1)); 
        num[0] = 1; 
        for (int i = 1; i <= n; ++i) { 
            for (int j = 1; j <= i; ++j) { 
                num[i] += num[j-1]*num[i-j]; 
            } 
        } 
        int res = num[n]; 
        delete[] num; 
        return res; 
    } 
};