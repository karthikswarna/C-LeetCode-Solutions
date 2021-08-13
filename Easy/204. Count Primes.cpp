class Solution {
public:
    // Sieve of Eratosthenes.
    int countPrimes(int n)
    {
        if(n <= 1) return 0;

        vector<bool> isPrime(n, true);    // We need to find primes "less than" n;
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i = 2; i <= sqrt(n); ++i)   // Start removing (striking off) non-primes.
        {
            if(isPrime[i])
                for(int j = 2; i * j < n; ++j)
                    isPrime[i * j] = false;
        }
        
        return count(isPrime.begin(), isPrime.end(), true);
    }
    
    
    // General prime checking.
//     int countPrimes(int n)
//     {
//         int count = 0;
        
//         for(int i = 2; i < n; ++i)     // 1 is neither prime nor composite.
//             if(isPrime(i))
//                 ++count;

//         return count;
//     }
    
    // Check if a number n is prime - sufficient to check its divisibility with numbers in range [2, sqrt{n}].
//     bool isPrime(int n)
//     {
//         for(int i = 2; i <= sqrt(n); ++i) 
//             if(n % i == 0)
//                 return false;
        
//         return true;
//     }
};