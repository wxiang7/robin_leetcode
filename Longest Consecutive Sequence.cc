class Solution { 
public: 
    int longestConsecutive(vector<int> &num) { 
        map<int, int> range; 
        map<int, int> range_len; 
        int res = 0; 
        for (int i = 0; i < num.size(); ++i) { 
            auto it = range.find(num[i]); 
            if (it == range.end()) { 
                int former = num[i]-1 
                  , next = num[i]+1; 
                auto f_it = range.find(former) 
                   , n_it = range.find(next); 
                range[num[i]] = num[i]; 
                range_len[num[i]] = 1; 
                res = max(res, range_len[num[i]]); 
                if (f_it != range.end()) { 
                    range[num[i]] = range[former]; 
                    range_len[num[i]] = 0; 
                    int parent = former; 
                    while (range[parent] != parent) { 
                        former = range[parent]; 
                        range[parent] = range[former]; 
                        range_len[parent] = 0; 
                        parent = former; 
                    } 
                    range_len[parent] += 1; 
                    res = max(res, range_len[parent]); 
                } 
                if (n_it != range.end()) { 
                    int current_set = range[num[i]]; 
                    int current_set_size = range_len[current_set]; 
                    range[current_set] = next; 
                    range_len[current_set] = 0; 
                    int parent = current_set; 
                    while (range[parent] != parent) { 
                        former = range[parent]; 
                        range[parent] = range[former]; 
                        range_len[parent] = 0; 
                        parent = former; 
                    } 
                    if (current_set != parent) { 
                        range_len[parent] += current_set_size; 
                        res = max(res, range_len[parent]); 
                    } 
                } 
            } 
        } 
        return res; 
    } 
}; 