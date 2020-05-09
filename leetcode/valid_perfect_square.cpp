class Solution {
public:
    bool isSquare(int num, int l, int r){
        if(l>r) return false;
        int m = (l+r)/2;
        if(num > m*m) return isSquare(num, m+1, r);
        if(num < m*m) return isSquare(num, l, m-1);
        return true;
    }
    bool isPerfectSquare(int num) {
        if(num==1 || num==4) return true;
        if(num<4) return false;
        return isSquare(num, 1, 46340);
    }
};
/* testcases
16
0
1
2
3
4
5
6
7
8
9
651616
2147483647
-5
-25
1331
*/
