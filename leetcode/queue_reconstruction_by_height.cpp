class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
                                           return (a[0]>b[0]) || (a[0]==b[0] && a[1]<b[1]);});
        for(int i=0; i<people.size(); ++i){
            if(people[i][1]==res.size()) res.push_back(people[i]);
            else{
                res.insert(res.begin()+people[i][1], people[i]);
            }
        }
        return res;
    }
};
