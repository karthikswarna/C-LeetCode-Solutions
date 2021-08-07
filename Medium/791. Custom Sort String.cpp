class Solution {
public:
    string customSortString(string order, string str)
    {
        int n = str.size();
        string result = "";
        result += str.at(0);
        
        for(int i = 1; i < n; i++)
        {
            int currPos = order.find(str[i]);
            // If the current character is not in the order, can be inserted anywhere in result.
            if(currPos >= n)
                result += str[i];
            else
            {
                int flag = false;
                for(int j = 0; j < result.size(); j++)
                {
                    if(currPos < (order.find(result[j])))
                    {
                        flag = true;
                        result = result.substr(0, j) + str[i] + result.substr(j);
                        break;
                    }
                }
                if(flag == false)
                    result += str[i];
            }
        }
        
        return result;
    }
};