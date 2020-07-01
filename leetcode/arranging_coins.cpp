class Solution {
public:
    int arrangeCoins(int n) {
        // find k such that k(k+1)>2*n, return k-1
        long b = n;
        return int(sqrt(1+(b<<3))-1)>>1;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        int left=0;
        int right=n;
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;

            long long curr=((long long)(mid)*(mid+1))/2;

            if(curr<=n)
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};
