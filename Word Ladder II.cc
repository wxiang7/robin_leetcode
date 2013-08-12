class Solution { 
private: 
    vector<vector<string> > ret; 
    vector<string> cur; 
    void print(vector<vector<ushort> >& pre, vector<string>& words, 
               int depth, int widx) { 
        if (depth == 0) { 
			cur[depth] = words[widx]; 
            ret.push_back(cur); 
        } else { 
            cur[depth] = words[widx]; 
            for (auto p : pre[widx]) { 
                print(pre, words, depth-1, p); 
            } 
        } 
    } 
     
public: 
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) { 
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
  
        queue<ushort> forward; 
        vector<vector<ushort> > pre(n); 
         
        vector<char> taken(n, 0);  
        forward.push(src);  
        taken[src] = 1;    
        int res = 0, steps = 1;  
         
        while (!forward.empty()) {  
            vector<ushort> added; 
            int forward_size = forward.size();  
            for (int i = 0; i < forward_size; ++i) {  
                int fe = forward.front();  
                forward.pop();  
                vector<ushort>& fneighbor = dist[fe];    
                for (ushort fn : fneighbor) {    
                    if (taken[fn] == 0) {  
                        added.push_back(fn); 
                        forward.push(fn); 
                        pre[fn].push_back(fe); 
                        taken[fn] = 1;   
                    } else if (taken[fn] == 1) { 
                        pre[fn].push_back(fe); 
                    } 
                }  
            } 
            ++steps;  
            bool found = false; 
            for (auto ne : added) { 
                taken[ne] = 2; 
                if (ne == dst) { 
                    found = true; 
                    break; 
                } 
            } 
            if (found) { 
				res = steps; 
				break; 
			} 
        }    
   
        ret.clear(); 
        cur.resize(res); 
		if (res > 0) print(pre, words, res-1, dst); 
        return ret;  
    } 
}; 