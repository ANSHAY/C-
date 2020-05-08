class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros=0;
        int i = 0;
        int l = arr.size()-1;
        for(i=0; i<=l-zeros; ++i){
            if(arr[i]==0){
                if(i == l-zeros){
                    arr[l]=0;
                    l--;
                    break;
                }
                zeros++;
            }
        }
        i--;
        while(zeros>0 && l>=0 && i>=0){
            arr[l] = arr[i];
            if(arr[l] == 0){
                l--;
                zeros--;
                arr[l] = 0;
            }
            l--;
            i--;
        }
    }
/*
    void duplicateZeros(vector<int>& arr) {
        vector<int> buffer;
        for(int i:arr){
            buffer.push_back(i);
            if(i==0) buffer.push_back(i);
        }
        for(int i=0; i<arr.size(); ++i){
            arr[i] = buffer[i];
        }
    }
*/
};
