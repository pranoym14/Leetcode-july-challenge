class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=abs(5.5*(double)minutes-30*(double)hour);
        if(x<abs(360-x))
            return x;
        return abs(360-x);
        
    }
};