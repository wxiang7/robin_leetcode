class Solution { 
private: 
    vector<int> res; 
    vector<bool> order; 
     
    void gray(int depth, int n, int current) { 
        if (depth == n) { 
            res.push_back(current); 
        } else { 
            if (!order[depth]) {  // 0->1 
                gray(depth+1, n, current << 1); 
                gray(depth+1, n, (current << 1) + 1); 
                order[depth] = !order[depth]; 
            } else {  // 1->0 
                gray(depth+1, n, (current << 1) + 1); 
                gray(depth+1, n, current << 1); 
                order[depth] = !order[depth]; 
            } 
        } 
    } 
     
public: 
    vector<int> grayCode(int n) { 
        res.clear(); 
        res.reserve(1u<<(unsigned int)n); 
        order.clear(); 
        order.resize(n, false); 
        gray(0, n, 0); 
        return res; 
    } 
     
};