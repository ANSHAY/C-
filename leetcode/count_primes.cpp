/*
The Sieve of Eratosthenes is one of the most efficient ways to find all prime numbers up to n. But don't let that name scare you, I promise that the concept is surprisingly simple.
*?
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        int count = 0;
        for(int i=2; i*i<=n; ++i){
            if(!isprime[i]) continue;
            for(int j=i*i; j<n; j+=i){
                isprime[j] = false;
            }
        }
        for(int i=2; i<n; ++i){
            if(isprime[i]) count++;
        }
        return count;
    }
};
