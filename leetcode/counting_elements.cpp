class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, bool> myMap;
        int res = 0;
        for(int i:arr){
            if(myMap.count(i)==0){
                myMap[i] = true;
            }
        }
        for(int i:arr){
            if(myMap.count(i+1)){
                res++;
            }
        }
        return res;
    }
};
