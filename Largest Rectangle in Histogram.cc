class Solution {  
public:  
    int largestRectangleArea(vector<int> &height) {  
        int len = height.size();  
        if (len == 0) return 0;  
          
        int* left = new int[len];  
        int* right = new int[len];  
          
        left[0] = 0;  
        for (int i = 1; i < len; ++i) {  
            if (height[i] > height[i-1]) {  
                left[i] = i;  
            } else {  
                int lm = left[i - 1]; 
                while (lm > 0 && height[lm-1] >= height[i]) { 
                    lm = left[lm-1]; 
                } 
                left[i] = lm; 
            }  
        }  
        right[len-1] = len-1;  
        for (int i = len-2; i >= 0; --i) {  
            if (height[i] > height[i+1]) {  
                right[i] = i;  
            } else { 
                int rm = right[i+1]; 
                while (rm < len-1 && height[rm+1] >= height[i]) { 
                    rm = right[rm+1]; 
                } 
                right[i] = rm;  
            }  
        }  
          
        int res = 0;  
        for (int i = 0; i < len; ++i) {  
            int area = height[i]*(right[i]-left[i]+1);  
            res = std::max(res, area);  
        }  
          
        delete[] left;  
        delete[] right;  
          
        return res;  
    }  
};