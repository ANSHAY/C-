class Solution {
public:
    /*
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        map<int, int> map;
        int last_key=0;
        for(vector<int> b:buildings){
            last_key = max(last_key, b[1]);
            for(int i=b[0]; i<b[1];++i){
                map[i] = max(b[2], map[i]);
            }
        }
        int cur=0;
        for(int i=0; i<=last_key;++i){
            if(cur!=map[i]){
                res.push_back(vector<int>{i, map[i]});
                cur = map[i];
            }
        }
        return res;
    }
    */
    class event{
        public:
        int index;
        int height;
        event(int i, int h):index(i), height(h){};
        bool operator<(event b){
            return this->index<b.index || (this->index==b.index && this->height>b.height);
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<event> events;
        multiset<int> ms;
        for(vector<int> b:buildings){
            events.push_back(event(b[0], b[2]));
            events.push_back(event(b[1], -b[2]));
        }
        sort(events.begin(), events.end());
        ms.insert(0);
        for(event e:events){
            cout<<'\n'<<e.index<<' '<<e.height;
            if(e.height>0){
                if(e.height>*ms.rbegin()){
                    res.push_back(vector<int>{e.index, e.height});
                }
                ms.insert(e.height);
            }
            else{
                if(*ms.rbegin() == -e.height){
                    // remove cur from max heap
                    ms.erase(ms.lower_bound(-e.height));
                    // check if new max equals cur
                    // if not then, push event in res
                    if(*ms.rbegin() != -e.height){
                        res.push_back(vector<int>{e.index, *ms.rbegin()});
                    }
                }
                else{
                    ms.erase(ms.lower_bound(-e.height));
                }
            }
            //cur = *ms.end(); // max from max heap
            cout<<"\ncur: "<<*ms.rbegin();
        }
        return res;
    }

};
