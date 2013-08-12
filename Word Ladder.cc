class Solution {   
public:   
    typedef unsigned short ushort;  
      
    int ladderLength(string start, string end, unordered_set<string> &dict) {   
        dict.insert(start);   
        dict.insert(end);   
        int n = dict.size()   
          , src = -1   
          , dst = -1   
          , m = start.length();   
        vector<string> words(dict.begin(), dict.end());   
        vector<vector<ushort> > dist(n, vector<ushort>(0));   
        for (int i = 0; i < n; ++i) {   
            const char* word = words[i].c_str();   
            if (src == -1 && strcmp(word, start.c_str()) == 0) src = i;   
            if (dst == -1 && strcmp(word, end.c_str()) == 0) dst = i;   
            for (int j = i+1; j < n; ++j) {   
                const char* second = words[j].c_str();   
                int differ = 0;   
                for (int k = 0; k < m; ++k) {   
                    if (word[k] != second[k]) ++differ;   
                    if (differ > 1) break;   
                }   
                if (differ == 1) {   
                    dist[i].push_back(j);   
                    dist[j].push_back(i);   
                }  
            }   
        }   
 
 
        queue<ushort> forward, back; 
        vector<char> taken(n, 0); 
        forward.push(src); 
        back.push(dst); 
        taken[src] = 1;  
        taken[dst] = 2;   
        bool found = false; 
        int res = 0, steps = 1; 
        while (!forward.empty() && !back.empty()) { 
            int forward_size = forward.size(); 
            for (int i = 0; i < forward_size; ++i) { 
                int fe = forward.front(); 
                forward.pop(); 
                vector<ushort>& fneighbor = dist[fe];   
                for (ushort fn : fneighbor) {   
                    if (taken[fn] == 2) {  
                        found = true; 
                        res = steps + steps; 
                        break; 
                    } else if (taken[fn] == 0) { 
                        forward.push(fn); 
                        taken[fn] = 1;  
                    }  
                } 
            } 
            if (found) break; 
            int back_size = back.size(); 
            for (int i = 0; i < back_size; ++i) { 
                int be = back.front(); 
                back.pop(); 
                vector<ushort>& bneighbor = dist[be];  
                for (ushort bn : bneighbor) {  
                    if (taken[bn] == 1) {  
                        found = true; 
                        res = steps + steps + 1; 
                        break; 
                    } else if (taken[bn] == 0) {  
                        back.push(bn); 
                        taken[bn] = 2;  
                    }  
                }     
            } 
            ++steps; 
            if (found) break; 
        }   
         
        return res; 
    }   
};  