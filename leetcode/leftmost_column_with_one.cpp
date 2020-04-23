/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        int min_col = cols;
        int l, r, p;
        for(int i=0; i<rows; ++i){
            l = 0;
            r = min_col;
            while(l<r){
                p = (l+r)/2;
                if(binaryMatrix.get(i, p) == 1){
                    r = p;
                }
                else{
                    l = p+1;
                }
            }
            min_col = r;
        }
        if(min_col == cols) return -1;
        return min_col;
    }
};
