class Solution { 
public: 
    int maxProfit(vector<int> &prices) { 
        if (prices.size() <= 1) return 0; 
        int res = 0 
          , min_price = prices[0]; 
        for (int i = 1; i < prices.size(); ++i) { 
            res = max(prices[i]-min_price, res); 
            min_price = min(prices[i], min_price); 
        } 
        return res; 
    } 
};