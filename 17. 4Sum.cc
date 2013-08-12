class Solution { 
public: 
    vector<vector<int> > fourSum(vector<int> &num, int target) { 
        vector<vector<int> > res; 
        vector<int> cur; 
        sort(num.begin(), num.end()); 
        int n = num.size(); 
        for (int i = 0; i < n - 3; ++i) { 
            cur.push_back(num[i]); 
            for (int j = i+1; j < n -2; ++j) { 
                cur.push_back(num[j]); 
                int prior = num[i] + num[j]; 
                int post = target - prior; 
                int from = j+1, to = n-1; 
                while (from < to) { 
                    int test = num[from] + num[to]; 
                    if (test == post) { 
                        cur.push_back(num[from]); 
                        cur.push_back(num[to]); 
                        bool exist_eq = false; 
                        for (const auto& r : res) { 
                            bool eq = true; 
                            for (int i = 0; i < 4; ++i) { 
                                if (r[i] != cur[i]) { 
                                    eq = false; 
                                    break; 
                                } 
                            } 
                            if (eq) { 
                                exist_eq = true; 
                                break; 
                            } 
                        } 
                        if (!exist_eq) { 
                            res.push_back(cur); 
                        } 
                        cur.pop_back(); 
                        cur.pop_back(); 
                        ++from; 
                        --to; 
                    } else if (test < post) { 
                        ++from; 
                    } else { 
                        --to; 
                    } 
                } 
                cur.pop_back(); 
            } 
            cur.pop_back(); 
        } 
        return res; 
    } 
}; 