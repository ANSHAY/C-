class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> myMap;
        int res = 0;
        for(int i:arr){
            if(myMap.count(i+1)>0){
                if(myMap[i+1] == 0){
                    res++;
                }
                else{
                    myMap[i+1]++;
                }
            }
            else{
                myMap[i+1] = 1;
            }
            if(myMap.count(i)>0){
                res += myMap[i];
                myMap[i] = 0;
            }
            else{
                myMap[i] = 0;
            }
        }
        return res;
    }
};
/* testcases
[1,2,3]
[1,1,2,2]
[1,3,2,3,5,0]
[1,1,3,3,5,5,7,7]
[52,5,4,7,8,9,6,5,4,1,2,0,3,20,2,1,5,4,7,8,5,4,6,5,5,6,5,8,97,4,5,1,2,3,6,5,8,9,78,4,5,1,2,0,3,2,02,6,5,8,98,5,47,8,7,4,58,0,5,6,85,6,8,6,56,8,0,56,8,6]
*/
