class Solution {
public:
    int myAtoi(string str) {
        int res=0;
        int i=0;
        int sign=1;
        while(str[i]==' ') i++;
        if(i>=str.size()) return 0;
        if(str[i]=='+'){
            sign = 1;
            i++;
        }
        else if(str[i]=='-'){
            sign = -1;
            i++;
        }
        while(str[i]>='0' && str[i]<='9'){
            int val = str[i] - '0';
            if((res>INT_MAX/10) || (res==INT_MAX/10 && val>7)) return INT_MAX;
            if((res<INT_MIN/10) || (res==INT_MIN/10 && val>8)) return INT_MIN;
            res = res*10 + sign*val;
            i++;
        }
        return res;
    }
};
