class Solution { 
private: 
    int largestRectangleArea(vector<int>& height) { 
        int len = height.size(); 
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
     
public: 
    int maximalRectangle(vector<vector<char> > &matrix) { 
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0; 
        int m = matrix.size() 
          , n = matrix[0].size(); 
        int res = 0; 
        vector<int> height(n, 0); 
        for (int i = 0; i < m; ++i) { 
            vector<char>& row = matrix[i]; 
            for (int j = 0; j < n; ++j) { 
                height[j] = row[j] == '1' ? height[j] + 1 : 0; 
            } 
            res = std::max(res, largestRectangleArea(height)); 
        } 
        return res; 
    } 
}; 
