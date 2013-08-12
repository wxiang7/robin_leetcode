class Solution { 
public: 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) { 
        if (obstacleGrid.size() == 0) return 0; 
         
        int m = obstacleGrid.size() 
          , n = obstacleGrid[0].size(); 
           
        if (n == 0) return 0; 
         
        int* count[2]; 
        count[0] = new int[m]; 
        count[1] = new int[m]; 
         
        memset(count[0], 0, sizeof(int)*m); 
        for (int i = 0; i < m; ++i) { 
            if (obstacleGrid[i][0]) { 
                break; 
            } 
            count[0][i] = 1; 
        } 
         
        bool current = true, last; 
        for (int i = 1; i < n; ++i) { 
            last = !current; 
            count[current][0] = obstacleGrid[0][i] ? 0 : count[last][0]; 
            for (int j = 1; j < m; ++j) { 
                if (obstacleGrid[j][i]) { 
                    count[current][j] = 0; 
                } else { 
                    count[current][j] = count[current][j-1] + count[last][j]; 
                } 
            } 
            current = last; 
        } 
         
        int res = count[!current][m-1]; 
        delete[] count[0]; 
        delete[] count[1]; 
        return res; 
    } 
};