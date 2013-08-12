class Solution {
public:
    int upper_bound(int A[], int from, int to, int target) {
        while (from < to) {
            if (to - from == 1) {
                if (A[to] == target)
                    return to;
                else if (A[from] == target)
                    return from;
                else
                    return -1;
            }
            int mid = (from + to) / 2;
            if (A[mid] > target) {
                to = mid-1;
            } else {
                from = mid;
            }
        }
        if (A[from] == target)
            return from;
        else
            return -1;
    }
    
    int lower_bound(int A[], int from, int to, int target) {
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
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        if (n == 0 || A[0] > target || A[n-1] < target) {
            ret.push_back(-1);
            ret.push_back(-1);
        }  else {
            ret.push_back(lower_bound(A, 0, n-1, target));
            ret.push_back(upper_bound(A, 0, n-1, target));
        }
        return ret;
    }
};
