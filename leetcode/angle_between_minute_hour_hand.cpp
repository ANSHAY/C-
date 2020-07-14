class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deg = abs(minutes*11/2.0 - hour*30);
        return min(deg, 360-deg);
    }
};
