class Solution { 
public: 
    int jump(int A[], int n) { 
        if (n <= 1) return 0; 
 
 
        int* steps = new int[n]; 
        int* start = new int[n]; 
         
        int infinet = 1000000; 
        for (int i = 0; i < n; ++i) { 
            steps[i] = infinet; 
            start[i] = 1; 
        } 
             
         
        steps[0] = 0; 
        for (int i = 0; i < n; ++i) { 
            int step = A[i]; 
            for (int j = start[i]; j <= step && i+j < n; ++j) { 
                int target = i+j; 
                if (steps[target] > steps[i] + 1) { 
                    steps[target] = steps[i]+1; 
                    start[target] = max(start[target], step-j); 
                } 
            } 
        } 
         
        int min_steps = steps[n-1]; 
        delete[] steps; 
        delete[] start; 
        return min_steps; 
    } 
};