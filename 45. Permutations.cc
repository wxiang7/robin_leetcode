class Solution { 
private: 
    vector<vector<int> > result; 
    vector<int> current; 
    bool* taken; 
     
    void permutation(vector<int> &num, int n, int depth) { 
        if (depth == n) { 
            for (vector<vector<int> >::reverse_iterator it = result.rbegin();  
                it != result.rend(); ++it) { 
                    bool equal = true; 
                    bool can_break = false; 
                    for (int i = 0; i < it->size(); ++i) { 
                        if ((*it)[i] > current[i]) { 
                            can_break = true; 
                            equal = false; 
                            break; 
                        } 
                    } 
                    if (equal) { 
                        return; 
                    } 
                } 
                result.push_back(current); 
        } else { 
            for (int i = 0; i < num.size(); ++i) { 
                if (!taken[i]) { 
                    current.push_back(num[i]); 
                    taken[i] = true; 
                    permutation(num, n, depth+1); 
                    taken[i] = false; 
                    current.pop_back(); 
                } 
            } 
        } 
    } 
     
public: 
    vector<vector<int> > permute(vector<int> &num) { 
        sort(num.begin(), num.end()); 
        result.clear(); 
        taken = new bool[num.size()]; 
        permutation(num, num.size(), 0); 
        delete[] taken; 
        return result; 
    } 
}; 
