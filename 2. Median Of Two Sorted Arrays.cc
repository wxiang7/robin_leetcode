class Solution {
  public:
    int kvalue(int A[], int m, int B[], int n, int k) {
      int a_left = m/2, a_right = m - a_left
        , b_left = n/2, b_right = n - b_left;
      int a = A[a_left], b = B[b_left];
      if (m == 0) {
        return B[k];   
      }
      if (n == 0) {
        return A[k];
      }
      if (m == 1 && n == 1) { // ensure (a_left != 0 || b_left != 0)
        if (k == 0)
          return a < b ? a : b;
        else
          return a < b ? b : a;
      }

      if (a_left + b_left < k) {
        if (a < b) {
          if (a_left > 0)
            return kvalue(A+a_left, a_right, B, n, k - a_left);
          else
            return kvalue(A, a_right, B+b_left, b_right, k - b_left);
        } else {
          if (b_left > 0)
            return kvalue(A, m, B+b_left, b_right, k - b_left);
          else
            return kvalue(A+a_left, a_right, B, n, k - a_left);
        }
      } else {
        if (a < b) {
          if (b_right > 0)
            return kvalue(A, m, B, b_left, k);
          else
            return kvalue(A, a_left, B, m, k);
        }
        else {
          if (a_right > 0)
            return kvalue(A, a_left, B, n, k);   
          else
            return kvalue(A, m, B, b_left, k);
        }
      }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
      if ((m+n) % 2 == 1)
        return kvalue(A, m, B, n, (m+n)/2);
      else
        return (kvalue(A, m, B, n, (m+n)/2) + 
            kvalue(A, m, B, n, (m+n)/2-1)) / 2.0f;
    }

};