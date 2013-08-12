class Solution { 
private: 
    vector<int> current; 
    vector<vector<int> > res; 
 
 
    void subset(int n, int next, vector<int>& S) { 
        if (next == n) { 
            res.push_back(current); 
        } else { 
            current.push_back(S[next]); 
            subset(n, next+1, S); 
            current.pop_back(); 
            subset(n, next+1, S); 
        } 
    } 
     
public: 
    vector<vector<int> > subsets(vector<int> &S) { 
        int length = S.size(); 
        sort(S.begin(), S.end()); 
        current.clear(); 
        res.clear(); 
        subset(length, 0, S); 
        return res; 
    } 
}; 