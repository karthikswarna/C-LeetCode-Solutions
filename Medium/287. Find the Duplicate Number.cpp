class Solution {
public:
    // Time: O(N), Space: O(1), Don't Modify the Array
    int findDuplicate(vector<int>& nums)
    {
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }

    // Time: O(N), Space: O(1), Modify the Array, Similar Technique to First Mising Positive
//     int findDuplicate(vector<int>& nums)
//     {
//         while(nums[0] != nums[nums[0]])
//             swap(nums[0], nums[nums[0]]);
    
//         return nums[0];
//     }

    // Time: O(N), Space: O(1), Modify the Array
//     int findDuplicate(vector<int>& nums)
//     {
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             int num = abs(nums[i]);

//             if(nums[num] < 0) return num;
//             else nums[num] = -nums[num];
//         }
        
//         return -1;
//     }
};