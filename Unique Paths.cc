class Solution { 
public: 
    int uniquePaths(int m, int n) { 
        int* count[2]; 
        count[0] = new int[m]; 
        count[1] = new int[m]; 
         
        for (int i = 0; i < m; ++i) { 
            count[0][i] = 1; 
        } 
         
        bool current = true; 
        for (int k = 1; k < n; ++k) { 
            bool last = !current; 
            count[current][0] = count[last][0]; 
            for (int i = 1; i < m; ++i) { 
                count[current][i] = count[last][i] + count[current][i-1]; 
            } 
            current = last; 
        } 
         
        int res = count[!current][m-1]; 
         
        delete[] count[0]; 
        delete[] count[1]; 
         
        return res; 
    } 
};