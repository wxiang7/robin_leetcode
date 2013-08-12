class Solution { 
public: 
    int longestValidParentheses(string s) { 
        int slen = s.length(), max_len = 0; 
        int *next = new int[slen]; 
        int *back = new int[slen+1]; 
        memset(next, 0, sizeof(int)*slen); 
        memset(back, 0, sizeof(int)*(slen+1)); 
		for (int start = slen-1; start >= 0; --start) { 
			int stack = 0; 
			int ptr = start; 
            if (s[start] == ')') { 
                back[start] = back[start+1] + 1; 
                continue; 
            } else { 
                back[start] = back[start+1]; 
            } 
			while (ptr < slen) { 
                if (next[ptr] > 0) { 
                    ++stack; 
                    ptr += next[ptr]-1; 
                    continue; 
                } 
				char ch = s[ptr]; 
				if (ch == '(') { 
					++stack; 
				} else if (stack > 0) { 
					--stack; 
					if (stack == 0) { 
						next[start] = ptr - start + 1; 
						max_len = max(max_len, next[start]); 
					} 
				} else { 
					break; 
				} 
				if (slen - ptr - 1 < stack) break; 
				if (back[ptr+1] < stack) break; 
				if (ptr + stack + next[ptr + stack] > slen) break; 
				++ptr; 
			} 
			if (slen - start < max_len) break; 
		} 
        delete[] next; 
        delete[] back; 
		return max_len; 
    } 
};