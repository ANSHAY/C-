class Solution {
public:
    double myPow2(double x, int n) {
        if(x==0 || x==1) return x;
        if(n==0) return 1;
        if(n<0){
            return myPow(x, n+1)/x;
        }
        return myPow(x, n-1)*x;
    }

    double myPow3(double x, int n) {
        if(x==0 || x==1) return x;
        if(n==0) return 1;
        int p=1;
        int z=1;
        while(true){
            z*=(n%2==0)?1:myPow(x, p);
            n/=2;
            p*=2;
            if(n==0) break;
        }
        return z;
    }

    double myPow1(double x, int n){
        if(n==0) return 1;
        int i=2;
        double p=x;
        while(i<=n){
            p = p*p;
            i *= 2;
        }
        for(int j=min(i-n, n-i/2); j>0; j--){
            p=p*x;
        }
        return p;
    }

    double pow(double x, int n){
        if(n==0) return 1;
        if(n%2){
            return x*pow(x*x, n>>1);
        }
        return pow(x*x, n>>1);
    }

    double myPow(double x, int n){
        if(x==0||x==1) return x;
        if(n==0) return 1;
        if(n<0){
            return 1/(x*pow(x, -(n+1)));
        }
        return pow(x, n);
    }
};
