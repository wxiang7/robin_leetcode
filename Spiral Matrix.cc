class Solution { 
public: 
    vector<int> spiralOrder(vector<vector<int> > &matrix) { 
        vector<int> res; 
        if (matrix.size() == 0 || matrix[0].size() == 0) return res; 
        int m = matrix.size(), n = matrix[0].size(); 
        int delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        int steps[4]; 
        steps[0] = n; 
        steps[1] = m; 
        steps[2] = n; 
        steps[3] = m-1; 
        int x = 0, y = 0, count = 0; 
         
        while (steps[0] > 0 && steps[1] > 0) { 
            for (int i = 0; i < 4; ++i) { 
                if (i > 1 && steps[i-1] < 2) break; 
                for (int j = 0; j < steps[i]-1; ++j) { 
                    res.push_back(matrix[x][y]); 
                    x += delta[i][0]; 
                    y += delta[i][1]; 
                    ++count; 
                } 
            } 
            if (count < n*m) { 
                res.push_back(matrix[x][y]); 
                ++count; 
                y += 1; 
            } 
            for (int i = 0; i < 4; ++i) { 
                steps[i] -= 2; 
            }    
        } 
         
        return res; 
    } 
}; 
 
 
class Solution { 
public: 
    vector<int> spiralOrder(vector<vector<int> > &matrix) { 
        vector<int> res; 
        if (matrix.size() == 0 || matrix[0].size() == 0) return res; 
         
        int m = matrix.size() 
          , n = matrix[0].size(); 
           
        int dx[] = {0, 1,  0, -1};  
        int dy[] = {1, 0, -1,  0};  
        int count = 0, target = n*m;  
        int x = 0, y = -1;  
        int steps[4];  
          
        steps[0] = n;  
        steps[1] = m-1;  
        steps[2] = n-1;  
        steps[3] = m-2; 
          
        res.reserve(target); 
        while (count < target) { 
            if (steps[1] <= 0) steps[2] = 0; 
            if (steps[0] <= 1) steps[3] = 0; 
            for (int i = 0; i < 4; ++i) {  
                for (int j = 0; j < steps[i]; ++j) {  
                    x += dx[i];  
                    y += dy[i];  
                    res.push_back(matrix[x][y]); 
                    count++;  
                }  
                steps[i] -= 2;  
            }  
        }  
          
        return res; 
    } 
}; 