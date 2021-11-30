class StockSpanner
{
    stack<pair<int, int>> S;    // Monotonixtack.

public:
    StockSpanner()
    { }

    int next(int price)
    {
        int span = 1;
        while(!S.empty() && S.top().first <= price)
        {
            span += S.top().second;
            S.pop();
        }

        S.push({price, span});
        return span;
    }

    // First Solution - To avoid the temporary stack, we use a stack of pairs and store the span of the last price.
//     int next(int price)
//     {
//         int span = 1;
//         stack<int> temp = S;

//         while(!temp.empty() && temp.top() <= price)
//         {
//             ++span;
//             temp.pop();
//         }

//         S.push(price);
//         return span;
//     }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */