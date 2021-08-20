class Solution {
public:
    // Bottom-Up (Tabulation)
    bool canJump(vector<int>& nums)
    {
        int N = nums.size();
        
        vector<bool> canReachFinalPos(N, false);
        canReachFinalPos[N - 1] = true;     // last position can be reached from itself.

        int prevTruePos = N - 1;
        for(int i = nums.size() - 2; i >= 0; --i)
        {
            // If the current element can atleat reach the nearest TRUE position.
            // i + nums[i] is max reachable position.
            if(i + nums[i] >= prevTruePos)
            {
                canReachFinalPos[i] = true;
                prevTruePos = i;
            }
        }
        
        return canReachFinalPos[0];
    }

    // Top-Down (Memoization)
    //     bool canJump(vector<int>& nums)
//     {
//         vector<bool> visitedMemo(nums.size(), false);
//         return canJumpUtil(nums, 0, visitedMemo);
//     }
    
//     bool canJumpUtil(vector<int> &nums, int curr, vector<bool> &visitedMemo)
//     {
//         if(curr == nums.size() - 1) return true;
//         if(nums[curr] == 0) return false;
//         if(visitedMemo[curr]) return false; // If this index is already visited, it means no solution was found.

//         for(int i = 1; (i <= nums[curr]) && (curr + i < nums.size()); ++i)
//             if(canJumpUtil(nums, curr + i, visitedMemo))
//                 return true;
        
//         visitedMemo[curr] = true;
//         return false;
//     }
};