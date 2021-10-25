class Solution {
public:
    // What a solution this is!!! :
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
    
    int maxProfit(vector<int>& prices)
    {
        int length = prices.size();
        vector<int> buy(length + 1, 0);     // length + 1 : Just to have cleaner code.
        vector<int> sell(length + 1, 0);
        
        buy[1] = -prices[0];
        for(int i = 2; i <= length; ++i)
        {
            int price = prices[i - 1];

            // buy on i-th day - maximum profit is sell[i - 2] - price, because on the (i-1)th day we can only cooldown.
            // or wait on i-th day for better price, nothing is done on ith day, do buy[i] = buy[i - 1].
            buy[i] = std::max(sell[i - 2] - price, buy[i - 1]);
            
            // sell on i-th day - maximum profit is buy[i - 1] + price - because we have to buy before we can sell.
            // or wait on ith day for better price - nothing is done on ith day, do sell[i] = sell[i - 1].
            sell[i] = std::max(buy[i - 1] + price, sell[i - 1]);
        }
        
        // We can't just buy on the last day and expect profits (cuz we cannot sell it later.)
        // So we just sell on the last day.
        return sell[length];
    }
};