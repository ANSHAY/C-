class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        res.push_back(vector<int>{1});
        for(int i=1; i<numRows; ++i){
            vector<int> temp = res.back();
            for(int j=temp.size()-1; j>0;--j){
                temp[j]+=temp[j-1];
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};
