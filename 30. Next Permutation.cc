class Solution {
public:
    void reverse(vector<int>& num, int from) {
        int end = num.size() - 1, tmp;
        while (from < end) {
            tmp = num[end];
            num[end] = num[from];
            num[from] = tmp;
            ++from;
            --end;
        }
    }
    
    void nextPermutation(vector<int> &num) {
        if (num.size() == 0 || num.size() == 1) return;
        int end = num.size() - 1;
        while (end > 0 && num[end-1] >= num[end]) --end;
        if (end == 0) {
            reverse(num, 0);
        } else {
            --end;
            int tail = num.size() - 1, tmp;
            while (num[tail] <= num[end]) --tail;
            tmp = num[tail];
            num[tail] = num[end];
            num[end] = tmp;
            reverse(num, end+1);
        }
    }
};
