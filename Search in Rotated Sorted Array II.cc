class Solution { 
private: 
    bool binsearch(int A[], int from, int to, int target) { 
        if (A[from] > target || A[to] < target) return false; 
        while (from < to) { 
            int mid = (from + to) / 2; 
            if (A[mid] >= target) { 
                to = mid; 
            } else { 
                from = mid+1; 
            } 
        } 
        return A[from] == target; 
    } 
     
public: 
    bool search(int A[], int n, int target) { 
        int head = 0; 
        while (head + 1 < n && A[head] <= A[head+1]) ++head; 
        bool res = binsearch(A, 0, head, target); 
        if (!res && head < n-1) { 
            res = binsearch(A, head+1, n-1, target); 
        } 
        return res; 
    } 
};