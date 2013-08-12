class Solution { 
public: 
    vector<string> anagrams(vector<string> &strs) { 
        map<string, vector<int> > index; 
        for (int i = 0; i < strs.size(); ++i) { 
            string str = strs[i]; 
            sort(str.begin(), str.end()); 
            index[str].push_back(i); 
        } 
        vector<string> res; 
        for (auto& pr : index) { 
            if (pr.second.size() > 1) { 
                for (auto id : pr.second) { 
                    res.push_back(strs[id]); 
                } 
            } 
        } 
        return res; 
    } 
}; 