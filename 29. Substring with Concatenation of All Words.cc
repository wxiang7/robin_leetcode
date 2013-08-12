class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.size() == 0 || S.length() == 0) return ret;
        map<string, int> vocabulary;
        map<string, int> used;
        for (const auto& word : L) {
            map<string, int>::iterator it = vocabulary.find(word);
            if (it == vocabulary.end())
                vocabulary[word] = 1;
            else
                it->second += 1;
        }
        
        int word_len = L[0].length()
          , word_count = L.size()
          , substr_len = word_len * word_count
          , end = (int)(S.length()) - substr_len
          , taken_words;
        for (int pos = 0; pos <= end; ++pos) {
            taken_words = 0;
            used.clear();
            for (int ptr = pos; taken_words < word_count; ptr += word_len) {
                string sub = S.substr(ptr, word_len);
                map<string, int>::iterator vit = vocabulary.find(sub);
                if (vit == vocabulary.end()) break;
                map<string, int>::iterator uit = used.find(sub);
                if (uit == used.end() || uit->second < vit->second) {
                    ++taken_words;
                    if (uit == used.end())
                        used[sub] = 1;
                    else
                        uit->second += 1;
                } else {
                    break;
                }
            }
            if (taken_words == word_count) ret.push_back(pos);
        }
        
        return ret;
    }
};
