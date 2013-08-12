class Solution { 
private: 
    int* pos; 
    bool* col; 
    bool* left; 
    bool* right; 
    vector<vector<string> > ret; 
    set<int> possible; 
     
    void solve(int row, int n) { 
        if (row == n) { 
            vector<string> res; 
            for (int i = 0; i < n; ++i) { 
                string row; 
                for (int j = 0; j < pos[i]; ++j) 
                    row.push_back('.'); 
                row.push_back('Q'); 
                for (int j = pos[i]+1; j < n; ++j) 
                    row.push_back('.'); 
                res.push_back(row); 
            } 
            ret.push_back(res); 
        } else { 
            set<int> copied(possible); 
            for (auto p : copied) { 
                if (!col[p] && !left[row-p+n-1] && !right[row+p]) { 
                    possible.erase(p); 
                    pos[row] = p; 
                    col[p] = true; 
                    left[row-p+n-1] = true; 
                    right[row+p] = true; 
                    solve(row+1, n); 
                    col[p] = false; 
                    left[row-p+n-1] = false; 
                    right[row+p] = false; 
                    possible.insert(p); 
                } 
            } 
        } 
    } 
     
public: 
    vector<vector<string> > solveNQueens(int n) { 
        ret.clear(); 
        if (n > 0) { 
            col = new bool[n]; 
            pos = new int[n]; 
            left = new bool[n<<1]; 
            right = new bool[n<<1]; 
            memset(col, 0, n); 
            memset(left, 0, n<<1); 
            memset(right, 0, n<<1); 
            possible.clear(); 
            for (int i = 0; i < n; ++i) possible.insert(i); 
            solve(0, n); 
            delete[] pos; 
            delete[] col; 
            delete[] left; 
            delete[] right; 
        } 
        return ret; 
    } 
}; 