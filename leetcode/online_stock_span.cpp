class StockSpanner {
public:
    vector<int> prices;
    vector<int> spans;
    StockSpanner() {

    }

    int next(int price) {
        int i=prices.size()-1;
        int span=1;
        while(i>=0 && price>=prices[i]){
            span += spans[i];
            i -= spans[i];
        }
        prices.push_back(price);
        spans.push_back(span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
