class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int big=arr[arr.size()-1];
        int temp=0;
        for(int i=arr.size()-2; i>=0; --i){
            temp = arr[i];
            arr[i] = big;
            if(temp>big){
                big = temp;
            }
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
