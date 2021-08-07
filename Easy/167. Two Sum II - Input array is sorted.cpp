class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(M.find(complement) != M.end())
                return vector<int>{M[complement] + 1, i + 1};
            
            M[nums.at(i)] = i;
        }
        
        return vector<int>{};
        
        // Another Solution wth two pointers
//         int l = 0;
//         int r = numbers.size() -1;

//         while(l < r)
//         {
//             if(numbers[l] + numbers[r] == target)
//                 return {l + 1, r + 1};;
            
//             else if(numbers[l] + numbers[r] > target)
//                 r--;

//             else
//                 l++;
//         }
        
//         return {};
    }
};