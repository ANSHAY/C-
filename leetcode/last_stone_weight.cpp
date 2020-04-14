class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int s1, s2;
        while(!stones.empty()){
            sort(stones.begin(), stones.end());
            if(stones.size()>1){
                s1 = stones.back(); stones.pop_back();
                s2 = stones.back(); stones.pop_back();
                if(s1>s2) stones.push_back(s1-s2);
            }
            else if(stones.size()==1){
                return stones.back();
            }
            else return 0;
        }
        return 0;
    }
};
