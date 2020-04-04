class Solution {
public:
    void recPascal(vector<int>& row, int rowIndex){
        if(rowIndex == 0){
            row[0] = 1;
            return;
        }
        recPascal(row, rowIndex-1);
        for(int i=rowIndex-1; i>0; i--){
            row[i] += row[i-1];
        }
        row[rowIndex] = 1;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1);
        recPascal(row, rowIndex);
        return row;
    }
};
