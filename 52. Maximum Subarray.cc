class Solution { 
public: 
    int maxSubArray(int A[], int n) { 
        int sum = numeric_limits<int>::min() 
          , last = 0 
          , current; 
        for (int i = 0; i < n; ++i) { 
            current = A[i]; 
            if (last > 0) { 
                current += last; 
            } 
            last = current; 
            sum = max(sum, last); 
        } 
        return sum; 
    } 
};