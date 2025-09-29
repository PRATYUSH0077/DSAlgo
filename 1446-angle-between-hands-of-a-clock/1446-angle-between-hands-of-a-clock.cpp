class Solution {
public:
    double angleClock(int h, int m) {
        double angle_m=m/60.0*360;
        double angle_h=h*30+(( m/60.0)*30);
        double res=abs(angle_m-angle_h);

        return min(res,360-res);
        
    }
};