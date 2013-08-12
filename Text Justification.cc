class Solution { 
public: 
    vector<string> fullJustify(vector<string> &words, int L) { 
        vector<string>::iterator from = words.begin(); 
        vector<string>::iterator to; 
        vector<string> res; 
        while (from != words.end()) { 
            int length = -1, sumlen = 0; 
            to = from; 
            while (to != words.end() && length + 1 + to->length() <= L) { 
                length += 1 + to->length(); 
                sumlen += to->length(); 
                ++to; 
            } 
             
            int count = to - from; 
            int spaces = L - sumlen; 
             
            if (to != words.end()) { // not last line 
                int base = count == 1 ? spaces : spaces / (count - 1) 
                  , extra = spaces - base*(count-1); 
                ostringstream delema; 
                for (int i = 0; i < base; ++i) delema << ' '; 
                ostringstream buf; 
                while (from != to) { 
                    buf << *from; 
                    if (from+1 != to) { 
                        buf << delema.str(); 
                        spaces -= base; 
                        if (extra > 0) { 
                            buf << ' '; 
                            --extra; 
                            --spaces; 
                        } 
                    } 
                    ++from; 
                } 
                while (spaces > 0) { 
                    buf << ' '; 
                    --spaces; 
                } 
                res.push_back(buf.str()); 
            } else { 
                ostringstream buf; 
                while (from != to) { 
                    buf << *from; 
                    if (from+1 != to) { 
                        buf << ' '; 
                        --spaces; 
                    } 
                    ++from; 
                } 
                while (spaces > 0) { 
                    buf << ' '; 
                    --spaces; 
                } 
                res.push_back(buf.str()); 
            } 
        } 
        return res; 
    } 
}; 