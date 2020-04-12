class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s_h=0;
        int t_h=0;
        int i=S.size()-1;
        int j=T.size()-1;
        while(i>=0 && j>=0){
            while(S[i]=='#' || s_h>0){
                if(S[i]=='#') s_h++;
                else s_h--;
                if(--i<0) break;
            }
            while(T[j]=='#' || t_h>0){
                if(T[j]=='#') t_h++;
                else t_h--;
                if(--j<0) break;
            }
            if(s_h==0 && t_h==0 && i>=0 && j>=0){
                if(S[i]!=T[j]) return false;
                i--;
                j--;
            }
        }
        if(i==-1 && j==-1) return true;
        if(i==-1){
            while(j>=0){
                if(T[j]=='#') t_h++;
                else{
                    if(t_h) t_h--;
                    else return false;
                }
                j--;
            }
            return true;
        }
        if(j==-1){
            while(i>=0){
                if(S[i]=='#') s_h++;
                else{
                    if(s_h) s_h--;
                    else return false;
                }
                i--;
            }
            return true;
        }
        return false;
    }
};
