class Solution { 
public: 
    vector<vector<int> > generate(int numRows) { 
        vector<vector<int> > res; 
        if (numRows == 0) return res; 
        vector<int> first(1, 1); 
        res.push_back(first); 
        for (int i = 1; i < numRows; ++i) { 
            vector<int>& last = res[i-1]; 
            vector<int> current; 
            current.reserve(last.size()+1); 
            current.push_back(1); 
            for (int i = 1; i < last.size(); ++i) { 
                current.push_back(last[i-1] + last[i]); 
            } 
            current.push_back(1); 
            res.push_back(current); 
        } 
        return res; 
    } 
}; 