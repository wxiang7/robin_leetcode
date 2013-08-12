class Solution { 
public: 
    int trap(int A[], int n) { 
        int *left = new int[n]; 
        int *right = new int[n]; 
        memset(left, 0, sizeof(int)*n); 
        memset(right, 0, sizeof(int)*n); 
         
        for (int i = 1, j = n-2; i < n; ++i, --j) { 
            left[i] = max(left[i-1], A[i-1]); 
            right[j] = max(right[j+1], A[j+1]); 
        } 
         
        int res = 0; 
        for (int i = 0; i < n; ++i) { 
            int height = min(left[i], right[i]); 
            if (height > A[i]) { 
                res += height - A[i]; 
            } 
        } 
         
        delete[] left; 
        delete[] right; 
        return res; 
    } 
}; 