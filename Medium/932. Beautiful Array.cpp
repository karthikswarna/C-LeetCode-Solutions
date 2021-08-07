class Solution {
public:
    vector<int> beautifulArray(int n)
    {        
        // We have all the odd numbers that are <= N in the left half of array. All the even numbers that are <= N on the right half of array. This way we cannot have the average of two numbers taken one from either side in between them. Now we need to maintain the condition among the each halfs. Find the pattern by taking down some examples.
        vector<int> result{1};
        while(result.size() < n)
        {
            vector<int> nextSeq;
            
            // Generating Odd numbers (<= N) using existing numbers.
            for(auto num : result)
                if(num * 2 - 1 <= n) 
                    nextSeq.push_back(num * 2 - 1);
            
            // Generating Even numbers (<= N) using existing numbers.
            for(auto num : result)
                if(num * 2 <= n)
                    nextSeq.push_back(num * 2);
        
            result = nextSeq;
        }
        
        return result;
    }
};