class Solution { 
public: 
    void solve(vector<vector<char>> &board) { 
        if (board.size() == 0 || board[0].size() == 0) return; 
        set<pair<int, int> > checked; 
        int dx[] = {0, 1, 0, -1}; 
        int dy[] = {1, 0, -1, 0}; 
        int m = board.size() 
          , n = board[0].size(); 
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) { 
                if (board[i][j] == 'X') continue; 
                pair<int, int> idx = make_pair(i, j); 
                if (checked.find(idx) == checked.end()) { 
                    checked.insert(idx); 
                    vector<pair<int, int> > flood; 
                    flood.push_back(idx); 
                    int ptr = 0; 
                    bool surrounded = true; 
                    while (ptr < flood.size()) { 
                        pair<int, int> top = flood[ptr]; 
                        for (int k = 0; k < 4; ++k) { 
                            int nx = top.first + dx[k] 
                              , ny = top.second + dy[k]; 
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) { 
                                surrounded = false; 
                            } else { 
                                pair<int, int> next = make_pair(nx, ny); 
                                if (board[nx][ny] == 'O' && checked.find(next) == checked.end()) { 
                                    flood.push_back(next); 
                                    checked.insert(next); 
                                } 
                            } 
                        } 
                        ++ptr; 
                    } 
                    if (surrounded) { 
                        for (auto& idx : flood) { 
                            board[idx.first][idx.second] = 'X'; 
                        } 
                    } 
                } 
            } 
        } 
    } 
};