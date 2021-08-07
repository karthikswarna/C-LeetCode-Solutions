class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int best_profit = INT_MIN;
        int best_buy_price = prices.at(0);
        for(int i = 1; i < prices.size(); i++)
        {
            // Take best price to buy till today and sell today OR Include today in best day to buy and sell in future.
            best_profit = std::max(prices.at(i) - best_buy_price, best_profit);
            best_buy_price = std::min(best_buy_price, prices.at(i));
        }
        
        return best_profit < 0 ? 0 : best_profit;
    }
};