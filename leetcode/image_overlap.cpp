/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int s=2*n-1, res=0;
        vector<vector<int>> C(3*n-2, vector<int>(3*n-2));
        for(int i=n-1, k=0; i<2*n-1; i++, k++){
            for(int j=n-1, l=0; j<2*n-1; j++, l++){
                C[i][j] = B[k][l];
            }
        }
        for(int i=0; i<s; i++){
            for(int j=0; j<s; j++){
                int sum = 0;
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        sum+=A[k][l]*C[i+k][j+l];
                    }
                }
                res = max(res, sum);
            }
        }
        return res;
    }
};
