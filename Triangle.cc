class Solution { 
public: 
    int minimumTotal(vector<vector<int> > &triangle) { 
        int height = triangle.size(); 
        if (height == 0) return 0; 
        int *row[2]; 
        bool last = false, current; 
     
        row[0] = new int[height]; 
        row[1] = new int[height]; 
        row[0][0] = triangle[0][0]; 
        for (int i = 1; i < height; ++i) { 
            vector<int>& tri_row = triangle[i]; 
            current = !last; 
            for (int j = 0; j <= i; ++j) { 
                if (j == 0) { 
                    row[current][j] = row[last][j]; 
                } else if (j == i) { 
                    row[current][j] = row[last][j-1]; 
                } else { 
                    row[current][j] = std::min(row[last][j], row[last][j-1]); 
                } 
                row[current][j] += tri_row[j]; 
            } 
            last = current; 
        } 
        int res = numeric_limits<int>::max(); 
        for (int i = 0; i < height; ++i) 
            res = std::min(res, row[last][i]); 
        delete[] row[0]; 
        delete[] row[1]; 
        return res; 
    } 
};