class Solution { 
public: 
    vector<vector<int> > generateMatrix(int n) { 
        vector<int> row_init(n); 
        vector<vector<int> > matrix(n, row_init); 
         
        int dx[] = {0, 1,  0, -1}; 
        int dy[] = {1, 0, -1,  0}; 
        int count = 1, target = n*n; 
        int x = 0, y = -1; 
        int steps[4]; 
         
        steps[0] = n; 
        steps[1] = n-1; 
        steps[2] = n-1; 
        steps[3] = n-2; 
         
        while (count <= target) { 
            for (int i = 0; i < 4; ++i) { 
                for (int j = 0; j < steps[i]; ++j) { 
                    x += dx[i]; 
                    y += dy[i]; 
                    matrix[x][y] = count++; 
                } 
                steps[i] -= 2; 
            } 
        } 
         
        return matrix; 
    } 
};