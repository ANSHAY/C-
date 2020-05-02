class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        for(char s:S){
            for(char j:J){
                if(s==j){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
