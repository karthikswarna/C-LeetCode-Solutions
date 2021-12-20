class Solution {
public:
    string decodeString(string s)
    {
        string result = s;
        string prevResult;

        while(prevResult != result)
        {
            prevResult = result;
            result = "";

            int freq = 0;
            int startId = -1;
            int openingCount = 0;

            for(int i = 0; i < prevResult.size(); ++i)
            {
                if(prevResult[i] == '[')
                {
                    if(startId == -1)
                        startId = i;

                    ++openingCount;
                }

                else if(prevResult[i] == ']')
                {
                    if(openingCount == 1)    // The closing bracket is found for the current char group.
                    {
                        while(freq > 0)
                        {
                            result += prevResult.substr(startId + 1, i - startId - 1);
                            --freq;
                        }

                        startId = -1;
                    }

                    --openingCount;
                }
                
                else if(startId == -1)
                {
                    if(prevResult[i] >= 48 && prevResult[i] <= 57)
                        freq = freq * 10 + (prevResult[i] - 48);
                    else
                        result += prevResult[i];
                }
            }
        }
        
        return prevResult;
    }
};