class Solution { 
public: 
    int removeDuplicates(int A[], int n) { 
        int ptr = 0 
          , current = 0 
          , repeated = 0 
          , count = 0; 
        while (ptr < n) { 
            if (current == A[ptr]) { 
                if (repeated < 2) { 
                    A[count] = A[ptr]; 
                    ++count; 
                    ++repeated; 
                } 
            } else { 
                current = A[ptr]; 
                repeated = 1; 
                A[count] = A[ptr]; 
                ++count; 
            } 
            ++ptr; 
        } 
        return count; 
    } 
};