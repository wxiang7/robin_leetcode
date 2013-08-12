class Solution {  
private: 
    bool* taken; 
    bool* col;  
    bool* left;  
    bool* right;  
    int ret;  
      
    void solve(int row, int n) {  
        if (row == n) {  
            ++ret; 
        } else {  
            for (int p = 0; p < n; ++p) { 
                if (!taken[p] && !col[p] && !left[row-p+n-1] && !right[row+p]) {  
                    col[p] = true;  
                    left[row-p+n-1] = true;  
                    right[row+p] = true;  
                    taken[p] = true; 
                    solve(row+1, n); 
                    taken[p] = false; 
                    col[p] = false;  
                    left[row-p+n-1] = false;  
                    right[row+p] = false;  
                }  
            } 
        }  
    }  
      
public:  
    int totalNQueens(int n) {  
        ret = 0; 
        if (n > 0) { 
            col = new bool[n]; 
            taken = new bool[n]; 
            left = new bool[n<<1];  
            right = new bool[n<<1];  
            memset(col, 0, n);  
            memset(taken, 0, n); 
            memset(left, 0, n<<1);  
            memset(right, 0, n<<1);  
            solve(0, n); 
            delete[] taken; 
            delete[] col;  
            delete[] left;  
            delete[] right;  
        }  
        return ret;  
    }  
};  