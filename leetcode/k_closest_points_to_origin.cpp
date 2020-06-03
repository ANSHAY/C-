class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    class Compare{
        public:
        bool operator()(const vector<int>& v1, const vector<int>& v2){
            return v1[0]*v1[0]+v1[1]*v1[1] > v2[0]*v2[0]+v2[1]*v2[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> mp;
        int i=0;
        for(vector<int> v:points){
            mp.push(v);
        }
        vector<vector<int>> res;
        for(int i=0; i<K; ++i){
            res.push_back(mp.top());
            mp.pop();
        }
        return res;
    }
};
