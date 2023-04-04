class Solution {
public:
    double angleClock(int hr, int min) {
        double hr1= 360/12, min1= hr1/5 , frac= (double)min/60;
        double hrAngle= (hr+frac)*hr1 , minAngle= min*min1;
        // cout<<hrAngle<<" "<<minAngle;
        double ans= abs(hrAngle- minAngle);
        return ans<180 ?ans: 360-ans;
    }
};