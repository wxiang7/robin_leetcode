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
private: 
    static bool interval_cmp(const Interval& a, const Interval& b) {  
        return a.start < b.start;  
    }  
public:  
    vector<Interval> merge(vector<Interval> &intervals) {  
        vector<Interval> ret;  
         
        sort(intervals.begin(), intervals.end(), interval_cmp);  
          
        vector<Interval>::iterator current = intervals.begin(), check;  
        while (current != intervals.end()) {  
            check = current;  
            ++check;  
            while (check != intervals.end()) {  
                if (check->start <= current->end) {  
                    current->end = std::max(current->end, check->end);  
                    ++check;  
                } else {  
                    break;  
                }  
            }  
            ret.push_back(*current);  
            current = check;  
        }  
        return ret;  
    }  
};  
 
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
private: 
    static bool interval_cmp(const Interval& a, const Interval& b) {  
        return a.start < b.start;  
    }  
public:  
    vector<Interval> merge(vector<Interval> &intervals) {  
        vector<Interval> ret;  
         
        sort(intervals.begin(), intervals.end(), interval_cmp);  
          
        vector<Interval>::iterator current = intervals.begin(), check;  
        while (current != intervals.end()) {  
            check = current;  
            ++check;  
            while (check != intervals.end()) {  
                if (check->start <= current->end) {  
                    current->end = std::max(current->end, check->end);  
                    ++check;  
                } else {  
                    break;  
                }  
            }  
            ret.push_back(*current);  
            current = check;  
        }  
        return ret;  
    }  
};  
