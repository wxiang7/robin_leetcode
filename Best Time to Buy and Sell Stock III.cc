class Solution {  
public:  
    int maxProfit(vector<int> &prices) {  
        if (prices.size() <= 1) return 0; 
        int n = prices.size();   
        vector<int> prior(n, 0); 
        int min_price = prices[0], res = 0; 
        for (int i = 1; i < n; ++i) { 
            prior[i] = max(prior[i-1], prices[i]-min_price); 
            res = max(prior[i], res); 
            min_price = min(min_price, prices[i]); 
        } 
        int max_price = prices[n-1]; 
        for (int i = n-2; i >= 2; --i) { 
            int prior_res = i > 0 ? prior[i-1] : 0; 
            int post_res = max_price-prices[i]; 
            res = max(res, max(prior_res, prior_res + post_res)); 
            max_price = max(max_price, prices[i]); 
        } 
        return res; 
    }  
};