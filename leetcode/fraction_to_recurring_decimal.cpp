/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, just return any of them.
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long num=numerator;
        long den=denominator;
        string res="";
        long i=0, ind=0, t;
        bool flag=false;
        i = num/den;
        res+=to_string(i);
        long f = num%den;
        if(f == 0){
            return res;
        }
        if(i==0 && ((num<0)^(den<0))) res="-0";
        f=max(f, -f);
        den = max(den, -den);
        res+='.';
        vector<int> rems;
        vector<int> digits;
        rems.push_back(f);
        while(true){
            if(f<den) f=f*10;
            t = f/den;
            digits.push_back(t);
            f = f%den;
            if(f==0){
                for(int d:digits) res+=to_string(d);
                return res;
            }
            for(int k=0; k<rems.size(); k++){
                if(rems[k]==f){
                    ind = k;
                    flag=true;
                }
            }
            if(flag) break;
            rems.push_back(f);
        }
        for(int l=0; l<digits.size(); l++){
            if(l==ind){
                res+="(";
            }
            res+=to_string(digits[l]);
        }
        res+=")";
        return res;
    }
};
