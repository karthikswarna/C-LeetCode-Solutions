const int MOD = 1e9 + 7;
class Solution {
public:
// Explanation:

    // The maximum SubArray of concatenated_arr can be the sum of all its elements.
    // For e.g.. if A is {3, 2, -1} and K is 3, then B will be {3, 2, -1, 3, 2, -1, 3, 2, -1}.
    // We can simply find the sum of all the elements in array A and we can mutilply it with K.
    // But wait, we can omit the last term in it so that the sum will become 13.
    // For this one we can use prefix and suffix calculations.
    // Eg:
    // A is repeated k times in concatenatedarr.
    // Say the array A after K repetitions is B. 
    // B array(K = 8) will be {A1, A2, A3, A4, A5, A6, A7, A8}. 
    // If you omit the first two elements in A1 and the last two elements in A8, you might also get the maxsub array.
    // So here we can check whether it is possible to omit some initial elements in A1 and some last elements in A8. 
    // answer = {prefix + sum_of_elements(A2) + sum_of_elements(A3) + sum_of_elements(A4) + sum_of_elements(A5) + sum_of_elements(A6) + sum_of_elements(A7) + suffix} 
    // ==> {prefix + sum_of_elements(A)*(k-2) + suffix}.

// Finally:
    // If k = 1, find the maximum sub-array sum in arr.
    // Else if k = 2 or sum(arr) <= 0, find the maximum sub-array sum in concat(arr, arr). (The maximum sub-array cannot contain a complete arr if sum(arr) <= 0)
    // Else find the maximum sub-array sum in concat(arr, arr) + sum(arr) * (k - 2).

    int kConcatenationMaxSum(vector<int>& arr, int k)
    {
        // Find Max Sum Subarray.
        long maxSubarraySum = arr[0];
        long localMax = arr[0];
        for(int i = 1; i < arr.size(); ++i)
        {
            localMax = std::max( (arr[i] + localMax) % MOD, (long)arr[i] );
            maxSubarraySum = std::max(localMax, maxSubarraySum);
        }

        if(k == 1)
            return std::max((long)0, maxSubarraySum); 


        // Find array Sum.
        long sum = accumulate(arr.begin(), arr.end(), 0);
        sum %= MOD;

        // Calculate Max Prefix Sum.
        long maxPrefixSum = 0;
        long runningSum = 0;
        for(int i = 0; i < arr.size(); ++i)
        {
            runningSum += arr[i] % MOD;
            maxPrefixSum = std::max(runningSum, maxPrefixSum);
        }

        // Calculate Max Suffix Sum.
        long maxSuffixSum = 0;
        runningSum = 0;
        for(int i = arr.size() - 1; i >= 0; --i)
        {
            runningSum += arr[i] % MOD;
            maxSuffixSum = std::max(runningSum, maxSuffixSum);
        }


        if(sum <= 0)
        {
            if(maxSubarraySum > maxSuffixSum + maxPrefixSum)
                return maxSubarraySum % MOD;
            else
                return (maxSuffixSum % MOD + maxPrefixSum % MOD) % MOD;
        }

        
        if(maxSubarraySum > maxSuffixSum + (k - 2)*sum + maxPrefixSum)
            return maxSubarraySum % MOD;
        else
            return (maxSuffixSum % MOD + ((k - 2)*sum) % MOD + maxPrefixSum % MOD) % MOD;

    }

    // Naive: Kadane's Algorithm on the array
//     int kConcatenationMaxSum(vector<int>& arr, int k)
//     {
//         long len = arr.size();
//         long newLen = len * k;
        
//         long max = arr[0];
//         long max_local = arr[0];
//         for(long i = 1; i < newLen; ++i)
//         {
//             if(arr[i % len] + max_local > arr[i % len])
//                 max_local = arr[i % len] + max_local;
//             else
//                max_local = arr[i % len];
            
//             max = std::max(max_local, max);
//         }
        
//         return max < 0 ? 0 : max % 1000000007;
//     }
};