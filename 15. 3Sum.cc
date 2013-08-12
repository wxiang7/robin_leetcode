class Solution {
public:
    void report(int fir, int sec, int thir, vector<vector<int> >* result) {
        vector<vector<int> >::reverse_iterator it;
        for (it = result->rbegin(); it != result->rend(); ++it) {
            if ((*it)[0] == fir && (*it)[1] == sec && (*it)[2] == thir)
                return;
            if ((*it)[0] != fir)
                break;
        }
        vector<int> to_add;
        to_add.push_back(fir);
        to_add.push_back(sec);
        to_add.push_back(thir);
        result->push_back(to_add);
    }
    
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for (int i = 0; i < len - 2; ++i) {
            int first = num[i]
              , remain = -first
              , begin = i+1
              , end = len - 1;
            while (begin < end) {
                int sum = num[begin] + num[end];
                if (sum == remain) {
                    report(first, num[begin], num[end], &result);
                    begin++;
                    end--;
                } else if (sum < remain) {
                    begin++;
                } else {
                    end--;
                }
            }
        }
        return result;
    }
};