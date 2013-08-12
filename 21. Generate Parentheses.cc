class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> result;
        if (n == 1) {
            result.insert("()");
        } else if (n > 1) {
            map<int, vector<string> > temp;
            for (int i = 1; i < n; ++i) {
                temp[i] = generateParenthesis(i);
            }
            for (const auto& res : temp[n-1]) {
                result.insert("(" + res + ")");
            }
            for (int i = 1; i < n; ++i) {
                for (const auto& pre : temp[i]) {
                    for (const auto& suf : temp[n-i]) {
                        string to_add = pre+suf;
                        if (result.find(to_add) == result.end())
                            result.insert(to_add);
                    }
                }
            }
        }
        vector<string> ret;
        for (const auto& str : result) {
            ret.push_back(str);
        }
        return ret;
    }
};