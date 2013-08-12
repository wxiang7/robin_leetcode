class Solution { 
private: 
    set<char> row_set[9]; 
    set<char> col_set[9]; 
    set<char> sub_set[9]; 
     
    bool solve(int count, vector<vector<char> >& board, 
               vector<pair<int, int> >& empty, 
               int current) { 
        if (count == 81) { 
            return true;     
        } else { 
            int x = empty[current].first, 
                y = empty[current].second; 
            set<char> possible; 
            int sub_idx = (x/3)*3+(y/3); 
            set_intersection(row_set[x].begin(), row_set[x].end(), 
                             col_set[y].begin(), col_set[y].end(), 
                             insert_iterator<set<char> >(possible, possible.begin())); 
            for (auto ch : possible) { 
                if (sub_set[sub_idx].find(ch) != sub_set[sub_idx].end()) { 
                        row_set[x].erase(ch); 
                        col_set[y].erase(ch); 
                        sub_set[sub_idx].erase(ch); 
                        board[x][y] = ch; 
                        if (solve(count+1, board, empty, current+1)) { 
                            return true; 
                        } 
                        board[x][y] = '.'; 
                        sub_set[sub_idx].insert(ch); 
                        col_set[y].insert(ch); 
                        row_set[x].insert(ch); 
                    } 
            } 
            return false; 
        } 
    } 
     
public: 
    void solveSudoku(vector<vector<char> > &board) { 
        int count = 0; 
        vector<pair<int, int> > empty; 
        for (int i = 0; i < 9; ++i) { 
            row_set[i].clear(); 
            col_set[i].clear(); 
            sub_set[i].clear(); 
            for (int j = 1; j < 10; ++j) { 
                row_set[i].insert('0'+j); 
                col_set[i].insert('0'+j); 
                sub_set[i].insert('0'+j); 
            } 
        } 
        for (int row = 0; row < 9; ++row) { 
            for (int col = 0; col < 9; ++col) { 
                char ch = board[row][col]; 
                if (ch != '.') { 
                    row_set[row].erase(ch); 
                    col_set[col].erase(ch); 
                    sub_set[(row / 3) * 3 +  (col / 3)].erase(ch); 
                    ++count; 
                } else { 
                    empty.push_back(make_pair(row, col)); 
                } 
            } 
        } 
        solve(count, board, empty, 0); 
    } 
}; 