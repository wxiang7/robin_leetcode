class Solution { 
public: 
    void merge(int A[], int m, int B[], int n) { 
        int check_a = 0 
          , check_b = 0 
          , put_a = 0 
          , next; 
        queue<int> buf; 
        while (check_a < m || check_b < n) { 
            if (check_b >= n || (check_a < m && A[check_a] <= B[check_b])) {  // fetch from A 
                next = A[check_a++]; 
            } else { 
                next = B[check_b++]; 
            } 
            if (check_a == m) check_a = m+n; 
            if (check_b == n) check_b = m+n; 
            while (put_a < check_a && !buf.empty()) { 
                A[put_a++] = buf.front(); 
                buf.pop(); 
            } 
            if (put_a < check_a) { 
                A[put_a++] = next; 
            } else { 
                buf.push(next); 
            } 
        } 
        while (!buf.empty()) { 
            A[put_a++] = buf.front(); 
            buf.pop(); 
        } 
    } 
}; 