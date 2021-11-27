class Solution
{
//First, if there's no zero in the array, then the subarray with maximum product must start with the first element or end with the last element. And therefore, the maximum product must be some prefix product or suffix product. So in this solution, we compute the prefix product A and suffix product B, and simply return the maximum of A and B.

// Why? Here's the proof:

// Say, we have a subarray A[i : j](i != 0, j != n) and the product of elements inside is P. Take P > 0 for example: if A[i] > 0 or A[j] > 0, then obviously, we should extend this subarray to include A[i] or A[j]; if both A[i] and A[j] are negative, then extending this subarray to include both A[i] and A[j] to get a larger product. Repeating this procedure and eventually we will reach the beginning or the end of A.

// What if there are zeroes in the array? Well, we can split the array into several smaller ones. That's to say, when the prefix product is 0, we start over and compute prefix profuct from the current element instead. And this is exactly what "prod = (prod != 0) ? prod : 1" does.
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        int result = INT_MIN;
        int prod = 1;
        
        for (int i = 0; i < n; ++i)
        {
            prod *= nums[i];
            result = max(prod, result);

            prod = (prod != 0) ? prod : 1;
        }

        prod = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            prod *= nums[i];
            result = max(prod, result);
            
            prod = (prod != 0) ? prod : 1;
        }

        return result;
    }
};