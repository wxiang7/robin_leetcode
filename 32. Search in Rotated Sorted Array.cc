class Solution {
public:
    int binSearch(int A[], int from, int to, int target) {
        if (A[from] > target || A[to] < target) return -1;
        while (from < to) {
            int mid = (from + to) / 2;
            if (A[mid] >= target) {
                to = mid;
            } else {
                from = mid+1;
            }
        }
        if (A[from] == target)
            return from;
        else
            return -1;
    }
    
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int pivot_from = 0
          , pivot_to = n-1
          , pivot_check
          , tail = n-1
          , check;
        bool rotated = n > 2 || (n == 2 && A[0] > A[1]);
        while (pivot_to - pivot_from > 1) {
            pivot_check = (pivot_from + pivot_to) / 2;
            check = A[pivot_check];
            if (A[0] < check && A[tail] < check) {
                pivot_from = pivot_check;
            } else if (A[0] > check && A[tail] > check){
                pivot_to = pivot_check;
            } else { // not rotated
                rotated = false;
                break;
            }
        }
        
        if (!rotated) {
            return binSearch(A, 0, n-1, target);
        } else if (A[0] <= target) {
            return binSearch(A, 0, pivot_from, target);
        } else {
            return binSearch(A, pivot_to, n-1, target);
        }
    }
};
