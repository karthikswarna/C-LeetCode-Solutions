class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        // Memoization
        // unordered_map<int, int> memo;
        // int result = coinChangeUtil(coins, amount, memo);
        // return result == INT_MAX ? -1 : result;
        
        // Tabulation
        vector<int> table(amount + 1, -1);
        table[0] = 0;
        
        for(int i = 0; i <= amount; i++)
        {
            if(table[i] != -1) // Only if possible to reach amount i.
            {
                for(auto j: coins)
                {
                    if(i <= amount - j)
                    {
                        if(table[i + j] == -1)
                            table[i + j] = table[i] + 1;
                        else
                            table[i + j] = std::min(table[i + j], table[i] + 1);
                    }
                }
            }
        }
        
        return table[amount];
    }
    
    int coinChangeUtil(vector<int>& coins, int amount, unordered_map<int, int> &memo)
    {
        if(memo.find(amount) != memo.end()) return memo[amount];
        
        if(amount < 0) return INT_MAX;  // Even infinite coins cannot make amount.
        if(amount == 0) return 0;       // 0 coins are needed to make amount 0
        
        int minCoins = INT_MAX;
        for(auto i : coins)
        {
            int count = coinChangeUtil(coins, amount - i, memo);
            if(count != INT_MAX && minCoins > count)
                minCoins = count + 1;
        }
        
        memo[amount] = minCoins;
        return minCoins;
    }
};