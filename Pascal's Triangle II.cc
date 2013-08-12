class Solution { 
public: 
    vector<int> getRow(int rowIndex) { 
        vector<int> row; 
        row.reserve(rowIndex+1); 
        row.push_back(1); 
        int last, cur; 
        for (int i = 1; i <= rowIndex; ++i) { 
            last = row[0]; 
            for (int i = 1; i < row.size(); ++i) { 
                cur = row[i]; 
                row[i] += last; 
                last = cur; 
            } 
            row.push_back(1); 
        } 
        return row; 
    } 
};