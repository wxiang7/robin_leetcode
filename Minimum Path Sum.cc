class Solution { 
public: 
    int minPathSum(vector<vector<int> > &grid) { 
        if (grid.size() == 0) return 0; 
        int m = grid.size() 
          , n = grid[0].size(); 
        if (n == 0) return 0; 
         
        int* sum[2]; 
        sum[0] = new int[m]; 
        sum[1] = new int[m]; 
        sum[0][0] = grid[0][0]; 
        for (int i = 1; i < m; ++i) 
            sum[0][i] = sum[0][i-1] + grid[i][0]; 
         
        bool current = true, last; 
        for (int i = 1; i < n; ++i) { 
            last = !current; 
            sum[current][0] = sum[last][0] + grid[0][i]; 
            for (int j = 1; j < m; ++j) { 
                sum[current][j] = std::min(sum[current][j-1], sum[last][j]) 
                                 + grid[j][i]; 
            } 
            current = last; 
        } 
         
        int res = sum[!current][m-1]; 
         
        delete[] sum[0]; 
        delete[] sum[1]; 
         
        return res; 
    } 
};