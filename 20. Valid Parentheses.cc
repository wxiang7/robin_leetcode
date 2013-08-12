class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        map<char, char> reverse;
        reverse[')'] = '(';
        reverse[']'] = '[';
        reverse['}'] = '{';
        for (const auto& ch : s) {
            if (ch == ')' || ch == ']' || ch == '}') {
                if (!container.empty() && container.top() == reverse[ch]) {
                    container.pop();
                } else {
                    return false;
                }
            } else {
                container.push(ch);
            }
        }
        return container.empty();
    }
};