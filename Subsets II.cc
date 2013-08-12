class Solution { 
private: 
    vector<vector<int> > res; 
    vector<int> current; 
     
    void subset(int next, int n, vector<int>& S) { 
        if (next == n) { 
            res.push_back(current); 
        } else { 
            int val = S[next] 
              , from = next; 
            while (next < n && S[next] == val) ++next; 
            subset(next, n, S); 
            for (int i = next-from; i > 0; --i) { 
                current.push_back(val); 
                subset(next, n, S); 
            } 
            for (int i = next-from; i > 0; --i) { 
                current.pop_back(); 
            } 
        } 
    } 
     
public: 
    vector<vector<int> > subsetsWithDup(vector<int> &S) { 
        sort(S.begin(), S.end()); 
        res.clear(); 
        current.clear(); 
        subset(0, S.size(), S); 
        return res; 
    } 
}; 