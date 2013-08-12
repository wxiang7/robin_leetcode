class Solution {  
public:  
    int maxProfit(vector<int> &prices) {  
        int n = prices.size();  
        if (n == 0) return 0;  
        vector<vector<int> > res(2, vector<int>(2, 0));  
        bool last = false, current;  
        res[0][0] = 0;  
        res[0][1] = -prices[0];  
        for (int i = 1; i < n; ++i) {  
            current = !last;  
            res[current][0] = std::max(res[last][0], res[last][1]+prices[i]); 
            res[current][1] = std::max(res[last][0]-prices[i], res[last][1]); 
            last = current;  
        }  
        return res[last][0];  
    }  
};