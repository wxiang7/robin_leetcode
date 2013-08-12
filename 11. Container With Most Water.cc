class Solution {
public:
    inline int min(int a, int b) {
        return a < b ? a : b;    
    }
    
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int maxArea(vector<int> &height) {
        int from = 0
          , to = height.size() - 1
          , max_area = (to - from) * min(height[from], height[to]);
        while (from < to) {
            if (height[from] < height[to]) {
                max_area = max(max_area, (to - from)*height[from]);
                from++;
            } else {
                max_area = max(max_area, (to - from)*height[to]);
                to--;
            }
        }
        return max_area;
    }
};

//Since i is lower than j, 
//so there will be no jj < j that make the area from i,jj 
//is greater than area from i,j
//so the maximum area that can benefit from i is already recorded.
//thus, we move i forward.


