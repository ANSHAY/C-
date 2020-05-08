class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<2) return false;
        if(coordinates.size()==2) return true;
        int m,c;
        if(coordinates[1][0] == coordinates[0][0]){
            for(vector<int> p:coordinates){
                if(p[0]!=coordinates[0][0]) return false;
            }
            return true;
        }
        else{
            m = (coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
            c = coordinates[0][1] - m*coordinates[0][0];
            for(int i=2; i<coordinates.size(); ++i){
                if(coordinates[i][1] != m*coordinates[i][0] + c) return false;
            }
            return true;
        }
        return false;
    }
};
