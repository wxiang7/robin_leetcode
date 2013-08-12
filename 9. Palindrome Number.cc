class Solution {
public:
    bool isPalindrome(int x) {
        int revised = 0
          , original = x;
        while (x > 0) {
            revised = revised*10 + x%10;
            x /= 10;
        }
        return revised == original;
    }
};