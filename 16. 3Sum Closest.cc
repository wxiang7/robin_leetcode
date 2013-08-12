class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size()
          , gap = INT_MAX
          , best_sum;
          
        sort(num.begin(), num.end());
        for (int i = 0; i < len - 2; ++i) {
            int first = num[i]
              , begin = i+1
              , end = len - 1
              , remain = target - first;
            while (begin < end) {
                int sum = num[begin] + num[end];
                if (sum == remain) {
                    return target;
                } else if (sum < remain) {
                    begin++;
                } else {
                    end--;
                }
                if (abs(first + sum - target) < gap) {
                    best_sum = first + sum;
                    gap = abs(best_sum - target);
                }
            }
        }
        return best_sum;
    }
};