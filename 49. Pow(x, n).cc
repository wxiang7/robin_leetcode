class Solution { 
public: 
    double pow(double x, int n) { 
        if (n == 0) 
            return 1.f; 
        else if (n > 0) { 
            double half = pow(x, n / 2); 
            if (n % 2 == 1) 
                return half * half * x; 
            else 
                return half * half; 
        } else if (n == -2147483648){ 
            double half = pow(x, 1073741824); 
            return 1 / (half * half); 
        } else { 
            return 1 / pow(x, -n); 
        } 
    } 
}; 