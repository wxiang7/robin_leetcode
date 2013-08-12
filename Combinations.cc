class Solution { 
private: 
    vector<int> current; 
    vector<vector<int> > res; 
    bool* taken; 
     
    void combination(int depth, int n, int k, int next) { 
        if (depth == k) { 
            res.push_back(current); 
        } else { 
            for (int i = next; i <= n; ++i) { 
                if (!taken[i]) { 
                    taken[i] = true; 
                    current.push_back(i); 
                    combination(depth+1, n, k, i+1); 
                    current.pop_back(); 
                    taken[i] = false; 
                } 
            } 
        } 
    } 
     
public: 
    vector<vector<int> > combine(int n, int k) { 
        res.clear(); 
        current.clear(); 
        taken = new bool[n+1]; 
        memset(taken, 0, sizeof(bool)*(n+1)); 
        combination(0, n, k, 1); 
        delete[] taken; 
        return res; 
    } 
};