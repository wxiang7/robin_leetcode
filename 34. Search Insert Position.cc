class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0 || A[0] >= target) {
            return 0;
        } else if (A[n-1] < target) {
            return n;  
        } else {
            int from = 0
              , to = n - 1;
            while (from < to) {
                if (to - from == 1) {
                    if (A[from] == target)
                        return from;
                    else
                        return to;
                }
                int mid = (from + to) / 2;
                if (A[mid] <= target) {
                    from = mid;
                } else {
                    to = mid;
                }
            }
            return from;
        }
    }
};