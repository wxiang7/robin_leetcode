class Solution {
public:
    string convert(string s, int nRows) {
      if (nRows <= 1 || s.length() <= nRows) {
        return s;
      } else {
        int m = (s.length() - 1) / (2*nRows - 2);
        int* pos = new int[2*m+3];
        string ret = s;
        int ptr = 0;

        int pos_len = 2*m+2;
        for (int i = 0; i <= m; ++i) {
          pos[2*i] = i*(2*nRows-2);
          pos[2*i+1] = i*(2*nRows-2);
          ret[ptr++] = s[pos[2*i]];
        }
        if (s.length() > (2*nRows-2)*m+nRows) {
          pos[2*m+2] = (2*nRows-2)*(m+1);
          pos_len += 1;
        }
        for (int r = 1; r < nRows-1; ++r) {
          for (int p = 0; p < pos_len; ++p) {
            if (p % 2 == 0)
              pos[p] -= 1;
            else
              pos[p] += 1;
            if (pos[p] >= 0 && pos[p] < s.length())
              ret[ptr++] = s[pos[p]];
          }
        }
        for (int p = 1; p <= 2*m+1; p += 2) {
          pos[p] += 1;
          if (pos[p] < s.length())
            ret[ptr++] = s[pos[p]];
        }

        return ret;
      }
    }
};