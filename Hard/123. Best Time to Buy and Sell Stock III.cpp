// Tabulation: 
// Let f[k, i] represent the max profit when we only trade from prices[0] to prices[i] (inclusive) using at most k transactions.

// Consider prices[i]: we may ignore it (downgrading to f[k, i-1]) or sell at prices[i]. If we sell at prices[i], we have to buy at some prices[j], j ∈ [0, i). Between j and i, no other trade can happen (required by the problem statement).

// We earn prices[i] - prices[j] in this trade, and at most k-1 trades are allowed before j. Among these trades, j should be excluded, since we buy at prices[j]. The profit in this case should be: prices[i] - prices[j] + f[k-1, j-1]. However, it is more convenient to use f[k-1, j] here (no need to worry about j-1<0). The extra option to buy and sell at prices[j] at the same time just means wasting a trade, which is allowed. Remember, we don't have to use up all the k trades.

// Final formula:
// f[k, i] = max(f[k, i-1], prices[i] - prices[j] + f[k-1, j]), j ∈ [0, i)
//          = max(f[k, i-1], prices[i] + max(f[k-1, j] - prices[j])), j ∈ [0, i)
// Initial conditions:
// f[0, i] = 0; 0 trade makes 0 profit
// f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade

class Solution
{
    // int maxPossibleProfit = 0;
public:
    int maxProfit(vector<int> &prices)
    {
        // Recursive Solution.
        // maxProfitUtil(prices, 0, 0, 0);
        // return maxPossibleProfit;

        // DP (Tabulation) Solution. (Generalized for K transactions.) 
        if(prices.size() <= 1) return 0;
                                                                            
        int K = 2; // number of max transation allowed
        vector<vector<int>> f(K + 1, vector<int>(prices.size(), 0));
        
        for(int k = 1; k <= K; k++)
        {
            int tmpMax = f[k - 1][0] - prices[0];
        
            for (int i = 1; i < prices.size(); i++)
            {
                f[k][i] = max(f[k][i - 1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, f[k - 1][i] - prices[i]);
            }
        }

        return f[K][prices.size() - 1];
    }

    // StockAction - previous action taken:
    // 0 - No action till now; -1 - bought first stock; 1 - Sold first stock
    // -2 - bought first stock; 2 - Sold second stock;
//     void maxProfitUtil(vector<int>& prices, int start, int currProfit, int stockAction)
//     {
//          // Only one day remaining, but nothing is bought
//         if((start == prices.size() - 1 && stockAction >= 0)
//            || start >= prices.size() 
//            || stockAction == 2)
//                 return;

//         // Stock is to be sold now.
//         if(stockAction < 0)
//             for(int i = start; i < prices.size(); ++i)
//             {
//                 maxPossibleProfit = std::max(currProfit + prices[i], maxPossibleProfit);
//                 maxProfitUtil(prices, i + 1, currProfit + prices[i], -stockAction);
//             }
    
//         // Buy the stock now.
//         else
//             for(int i = start; i < prices.size(); ++i)
//                 maxProfitUtil(prices, i + 1, currProfit - prices[i], -(stockAction + 1));
//     }
};