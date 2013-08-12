class Solution { 
public: 
    int climbStairs(int n) { 
        if (n <= 1) return 1; 
        int first = 1 
          , second = 1 
          , third; 
        for (int i = 2; i <= n; ++i) { 
            third = first + second; 
            if (i == n) return third; 
            first = second; 
            second = third; 
        } 
    } 
}; 
