class Solution {
  public:
    string longestPalindrome(string s) {
      int max_len = 1, max_start=0;
      bool palindrome[1000][1000] = {0};
      for (int i = s.length()-1; i > 0 ; --i) {
        palindrome[i][i] = true;
        if (s[i] == s[i-1]) {
          palindrome[i-1][i] = true;
          max_len = 2;
          max_start = i-1;
        }
      }
      palindrome[0][0] = true;

      for(int len = 3; len <= s.length(); ++len) {
        for (int start = 0; start <= s.length() - len; ++start) {
          int end = start+len-1;
          if (s[start] == s[end] && palindrome[start+1][end-1]) {
            palindrome[start][end] = true;
            if (max_len < len) {
              max_len = len;
              max_start = start;
            }
          }
        }
      }
      return s.substr(max_start, max_len);
    }
};