class Solution { 
public: 
    void rotateCorner(vector<vector<int> > &matrix, int pos[4][2]) { 
        int tmp = matrix[pos[3][0]][pos[3][1]]; 
        for (int i = 3; i > 0; --i) { 
            matrix[pos[i][0]][pos[i][1]] = matrix[pos[i-1][0]][pos[i-1][1]]; 
        } 
        matrix[pos[0][0]][pos[0][1]] = tmp; 
    } 
 
 
    void rotate(vector<vector<int> > &matrix) { 
        int n = matrix.size(); 
        int pos[4][2]; 
        for (int circle = 0; circle < n / 2; ++circle) { 
            pos[0][0] = circle; pos[0][1] = circle; 
            pos[1][0] = circle; pos[1][1] = n - circle - 1; 
            pos[2][0] = pos[2][1] = n - circle - 1; 
            pos[3][0] = n - circle - 1; pos[3][1] = circle; 
            for (int i = 0; i < n - 2*circle - 1; ++i) { 
                rotateCorner(matrix, pos); 
                pos[0][1] += 1; 
                pos[1][0] += 1; 
                pos[2][1] -= 1; 
                pos[3][0] -= 1; 
            } 
        } 
    } 
}; 