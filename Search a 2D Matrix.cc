class Solution { 
public: 
    bool searchMatrix(vector<vector<int> > &matrix, int target) { 
        if (matrix.size() == 0) return false; 
        int m = matrix.size() 
          , n = matrix[0].size(); 
        // search row 
        int from = 0 
          , to = m-1; 
        if (matrix[0][0] > target) return false; 
        while (from +1 < to) { 
            int mid = (from + to) / 2; 
            if (matrix[mid][0] > target) { 
                to = mid - 1; 
            } else { 
                from = mid; 
            } 
        } 
        if (from != to) { 
            from = (matrix[to][0] <= target) ? to : from; 
        } 
        // search in row[from] 
        vector<int>& row = matrix[from]; 
        from = 0; 
        to = n - 1; 
        if (row[to] < target) return false; 
        while (from < to) { 
            int mid = (from + to) / 2; 
            if (row[mid] >= target) { 
                to = mid; 
            } else { 
                from = mid + 1; 
            } 
        } 
        return row[from] == target; 
    } 
}; 