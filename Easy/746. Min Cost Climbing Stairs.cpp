class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> memo(cost.size(), -1);
        int min1 = minCostClimbingStairsUtil(cost, 0, memo);
        int min2 = minCostClimbingStairsUtil(cost, 1, memo);
        return std::min(min1, min2);
    }

    int minCostClimbingStairsUtil(vector<int> &cost, int current_step, vector<int> &memo)
    {
        if(memo.at(current_step) != -1)
            return memo.at(current_step);

        if(current_step >= cost.size() - 2)
            return cost.at(current_step);
        
        memo.at(current_step) = std::min(
            cost.at(current_step) + minCostClimbingStairsUtil(cost, current_step + 1, memo),
            cost.at(current_step) + minCostClimbingStairsUtil(cost, current_step + 2, memo)
            );

        return memo.at(current_step);
    }
};