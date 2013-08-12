class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        int len = 0, min_len = INT_MAX;
        for (const auto& str : strs) {
            if (str.length() < min_len)
                min_len = str.length();
        }
        if (strs.size() == 0) {
            min_len = 0;
        }
        while (len < min_len) {
            char test = strs[0][len];
            bool is_valid = true;
            for (const auto& str : strs) {
                if (str[len] != test) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                prefix.push_back(test);
                len++;
            } else {
                break;
            }
        }
        return prefix;
    }
};