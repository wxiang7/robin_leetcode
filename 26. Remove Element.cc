class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int *head = A, *tail = A+n-1;
        while (n > 0 && head != tail) {
            if (*head == elem) {
                *head = *tail;
                tail--;
                n--;
            } else {
                head++;
            }
        }
        if (n > 0 && head == tail && *head == elem) {
            n--;
        }
        return n;
    }
};