class Solution { 
private: 
    vector<vector<int> > result; 
    vector<int> current; 
    bool* reachable; 
 
 
    void print(vector<int>& candidates, int target, int last_index = 0) { 
        if (target == 0) { 
            for (const auto& comb : result) { 
                bool equal = comb.size() == current.size(); 
                if (equal) { 
                    for (int i = 0; i < comb.size(); ++i) { 
                        if (comb[i] != current[i]) { 
                            equal = false; 
                            break; 
                        } 
                    } 
                } 
                if (equal) { 
                    break; 
                } 
            } 
            result.push_back(current); 
        } else { 
            for (int i = last_index; i < candidates.size(); ++i) { 
                if (target >= candidates[i] && reachable[target-candidates[i]]) { 
                    current.push_back(candidates[i]); 
                    print(candidates, target-candidates[i], i); 
                    current.pop_back(); 
                } 
            } 
        } 
    } 
 
 
public: 
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) { 
        reachable = new bool[target+1]; 
        memset(reachable, 0, target+1); 
        reachable[0] = true; 
        sort(candidates.begin(), candidates.end()); 
        for (int sum = 1; sum <= target; ++sum) { 
            for (auto num : candidates) { 
                if ((sum >= num && reachable[sum-num]) || sum < num) { 
    reachable[sum] = true; 
                    break; 
                } 
            } 
        } 
        current.clear(); 
        result.clear(); 
        print(candidates, target); 
        delete[] reachable; 
        reachable = NULL; 
        return result; 
    } 
}; 