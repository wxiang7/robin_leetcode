/** 
 * Definition for an interval. 
 * struct Interval { 
 *     int start; 
 *     int end; 
 *     Interval() : start(0), end(0) {} 
 *     Interval(int s, int e) : start(s), end(e) {} 
 * }; 
 */ 
class Solution { 
public: 
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) { 
        vector<Interval> res; 
        vector<Interval>::iterator current = intervals.begin(), check; 
        bool merged = false, forward = true; 
        while (current != intervals.end()) { 
            if (!merged && newInterval.start < current->start) { 
                if (newInterval.end < current->start) { 
                    merged = true; 
                    forward = false; 
                    res.push_back(newInterval); 
                } else { 
                    current->start = newInterval.start; 
                    current->end = std::max(current->end, newInterval.end); 
                    merged = true; 
                    check = current; 
                    ++check; 
                } 
            } else if (!merged && current->end >= newInterval.start) { 
                current->end = std::max(current->end, newInterval.end); 
                merged = true; 
                check = current; 
                ++check; 
            } else if (merged) { 
                check = current; 
                ++check; 
            } 
             
            if (forward && merged) { 
                while (check != intervals.end()) { 
                    if (current->end >= check->start) { 
                        current->end = std::max(current->end, check->end); 
                        ++check; 
                    } else { 
                        forward = !merged; 
                        break; 
                    } 
                } 
                res.push_back(*current); 
                current = check; 
            } else { 
                res.push_back(*current); 
                ++current; 
            } 
        } 
         
        if (!merged) { 
            res.push_back(newInterval); 
        } 
         
        return res; 
    } 
};