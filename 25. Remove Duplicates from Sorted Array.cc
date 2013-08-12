class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int counter = 0
          , current = numeric_limits<int>::min()
          , *ptr = A;
        for (int i = 0; i < n; ++i) {
            if (current < A[i]) {
                counter++;
                current = A[i];
                *(ptr++) = current;
            }
        }
        return counter;
    }
};