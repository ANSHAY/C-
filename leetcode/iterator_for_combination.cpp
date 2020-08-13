/*
Design an Iterator class, which has:

    A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
    A function next() that returns the next combination of length combinationLength in lexicographical order.
    A function hasNext() that returns True if and only if there exists a next combination.

*/
class CombinationIterator {
public:
    vector<string> combs;
    string inp;
    int ind=-1;
    void combins(vector<string>& combs, string s, int start, int l){
        if(s.size()==l){
            combs.push_back(s);
            return;
        }
        for(int i=start; i<inp.size(); ++i){
            s.push_back(inp[i]);
            combins(combs, s, i+1, l);
            s.pop_back();
        }
        return;
    }

    CombinationIterator(string characters, int combinationLength) {
        inp = characters;
        combins(combs, "", 0, combinationLength);
    }

    string next() {
        ind++;
        return combs[ind];
    }

    bool hasNext() {
        return ind+1<combs.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
