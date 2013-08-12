class Solution { 
public: 
    void setZeroes(vector<vector<int> > &matrix) { 
        if (matrix.size() == 0) return; 
        int m = matrix.size() 
          , n = matrix[0].size(); 
        bool *row = new bool[m]; 
        bool *col = new bool[n]; 
        memset(row, 0, sizeof(bool)*m); 
        memset(col, 0, sizeof(bool)*n); 
        for (int i = 0; i < m; ++i) { 
            vector<int>& rowv = matrix[i]; 
            for (int j = 0; j < n; ++j) { 
                if (rowv[j] == 0) { 
                    row[i] = true; 
                    col[j] = true; 
                } 
            } 
        } 
        for (int i = 0; i < m; ++i) { 
            if (row[i]) { 
                for (int j = 0; j < n; ++j) { 
                    matrix[i][j] = 0; 
                } 
            } 
        } 
        for (int j = 0; j < n; ++j) { 
            if (col[j]) { 
                for (int i = 0; i < m; ++i) { 
                    matrix[i][j] = 0; 
                }    
            } 
        } 
        delete[] row; 
        delete[] col; 
    } 
}; 