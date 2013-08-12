class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() !=9 || board[0].size() != 9) return false;
        // test row
        set<char> taken;
        for (auto& row : board) {
            taken.clear();
            for (auto& ch : row) {
                if (ch == '.') continue;
                if (taken.find(ch) == taken.end()) {
                    taken.insert(ch);
                } else {
                    return false;
                }
            }
        }
        
        // test column
        for (int col = 0; col < board[0].size(); ++col) {
            taken.clear();
            for (auto& row : board) {
                char ch = row[col];
                if (ch == '.') continue;
                if (taken.find(ch) == taken.end()) {
                    taken.insert(ch);
                } else {
                    return false;
                }
            }
        }
        
        // test subbox
        for (int row = 0; row < board.size() - 2; row+=3) {
            for (int col = 0; col < board.size() - 2; col+=3) {
                taken.clear();
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        char ch = board[row+x][col+y];
                        if (ch == '.') continue;
                        if (taken.find(ch) == taken.end()) {
                            taken.insert(ch);
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        
        // passed all tests
        return true;
    }
};
