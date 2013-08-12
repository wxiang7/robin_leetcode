class Solution { 
private: 
    bool exist(int x, int y, vector<vector<char> >& board, const char* ch) { 
        if (*ch == 0) { 
            return true; 
        } else { 
            int dx[] = {0, 1,  0, -1} 
              , dy[] = {1, 0, -1,  0}; 
            for (int i = 0; i < 4; ++i) { 
                int nx = x + dx[i] 
                  , ny = y + dy[i]; 
                if (nx >= 0 && nx < board.size() && 
                    ny >= 0 && ny < board[0].size() && 
                    board[nx][ny] == *ch) { 
                    board[nx][ny] = 0; 
                    bool ret = exist(nx, ny, board, ch+1); 
                    if (ret) return true; 
                    board[nx][ny] = *ch; 
                } 
            } 
        } 
    } 
     
public: 
    bool exist(vector<vector<char> > &board, string word) { 
        const char* ptr = word.c_str(); 
        if (board.size() == 0 || board[0].size() == 0) return false; 
        int m = board.size() 
          , n = board[0].size(); 
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) { 
                if (board[i][j] == *ptr) { 
                    board[i][j] = 0; 
                    bool ret = exist(i, j, board, ptr+1); 
                    if (ret) return true; 
                    board[i][j] = *ptr; 
                } 
            } 
        } 
    } 
}; 