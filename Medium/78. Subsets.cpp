class Solution {
public:
    // subsets([1,2,3,4]) = []
    //                  // push(1)
    //                  [1, subsets([2,3,4])] 
    //                  // pop(), push(2)
    //                  [2, subsets([3,4])]
    //                  // pop(), push(3)
    //                  [3, subsets([4])]
    //                  // pop(), push(4)
    //                  [4, subsets([])]
    //                  // pop()

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        
        generateSubsets(nums, result, subset, 0);
        
        return result;
    }
    
    void generateSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int begin)
    {
        result.push_back(subset);
        
        for(int i = begin; i < nums.size(); ++i)
        {
            subset.push_back(nums[i]);
            generateSubsets(nums, result, subset, i + 1);
            subset.pop_back();
        }
    }
};