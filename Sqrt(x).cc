class Solution { 
public: 
    int sqrt(int x) { 
        const int max_res = 46340; 
        if (x >= max_res*max_res) return max_res; 
        if (x <= 0) return 0; 
        int from = 0 
          , to = max_res; 
        while (from < to) { 
            int mid = (from + to) / 2; 
            int pivot = mid*mid; 
            if (pivot == x) { 
                return mid; 
            } else if (pivot < x) { 
                from = mid; 
            } else { 
                to = mid; 
            } 
            if (from + 1 == to) return from; 
        } 
        return from; 
    } 
};