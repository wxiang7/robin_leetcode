class Solution { 
private: 
    bool **reachable; 
    vector<vector<int> > result; 
    vector<int> current; 
     
    void createReachable(int target, int num_size) { 
        reachable = new bool*[target+1]; 
        for (int i = 0; i <= target; ++i) { 
            reachable[i] = new bool[num_size]; 
            memset(reachable[i], 0, sizeof(bool)*num_size); 
        } 
         
        for (int i = 0; i < num_size; ++i) { 
reachable[0][i] = true; 
} 
    } 
     
    void freeReachable(int target) { 
        for (int i = 0; i <= target; ++i) 
            delete[] reachable[i]; 
        delete[] reachable; 
    } 
     
    void print(vector<int>& num, int target, int last_index) { 
        if (target == 0) { 
            vector<int> to_add; 
            to_add.reserve(current.size()); 
            for (vector<int>::reverse_iterator it = current.rbegin(); 
                it != current.rend(); ++it) { 
                    to_add.push_back(*it); 
            } 
            for (const auto& comb : result) { 
                bool equal = comb.size() == current.size(); 
                if (equal) { 
                    for (int i = 0; i < comb.size(); ++i) { 
                        if (comb[i] != to_add[i]) { 
                            equal = false; 
                            break; 
                        } 
                    } 
                } 
                if (equal) { 
                    return; 
                } 
            } 
            result.push_back(to_add); 
        } else { 
            for (int i = last_index; i >= 0; --i) { 
                if ((i == 0 && target == num[i]) || 
                    (i > 0 && target >= num[i] && reachable[target-num[i]][i-1])) { 
                    current.push_back(num[i]); 
                    print(num, target-num[i], i-1); 
                    current.pop_back(); 
                } 
            } 
        } 
    } 
     
public: 
    vector<vector<int> > combinationSum2(vector<int> &num, int target) { 
        if (num.size() == 0) return result; 
        sort(num.begin(), num.end()); 
        createReachable(target, num.size()); 
        for (int sum = 1; sum <= target; ++sum) { 
            for (int i = 0; i < num.size(); ++i) { 
                if (i > 0) { 
                    reachable[sum][i] = reachable[sum][i-1]; 
                    if (!reachable[sum][i] && sum >= num[i]) { 
                        reachable[sum][i] = reachable[sum-num[i]][i-1]; 
                    } 
                } else if (sum == num[i]) { 
                    reachable[sum][i] = true; 
                } 
            } 
        } 
        result.clear(); 
        current.clear(); 
        print(num, target, num.size()-1); 
        freeReachable(target); 
        return result; 
    } 
}; 
