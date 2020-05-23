class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if(A.empty() || B.empty()) return res;
        vector<int> temp(2);
        int i=0, j=0;
        while(i<A.size() && j<B.size()){
            if(A[i][0]>B[j][1]){
                ++j;
            }
            else if(A[i][1]<B[j][0]){
                ++i;
            }
            else{
                // intersacting
                temp[0] = max(A[i][0], B[j][0]);
                temp[1] = min(A[i][1], B[j][1]);
                res.push_back(temp);
                if(A[i][1]<B[j][1]) ++i;
                else ++j;
            }
        }
        return res;
    }
};
/* testcases
[]
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
[]
[[0,2],[5,10],[13,23],[24,25]]
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
[[1,5],[8,12],[15,24],[25,26]]
[[0,1],[5,8],[12,23],[15,25]]
[[1,5],[8,12],[15,24],[25,26]]
[[0,0],[0,0],[0,0],[0,0]]
[[0,0],[0,0],[0,0],[0,0]]
[[1,5],[8,12],[15,24],[29,36]]
[[6,7],[13,14],[25,28],[37,46]]
[[1,7]]
[[2,9]]
[[1,7]]
[[2,6]]
[[3,7]]
[[8,9]]
[[3,7]]
[[0,2]]
[[1,7]]
[[0,4]]
[[1,7]]
[[0,9]]
*/
