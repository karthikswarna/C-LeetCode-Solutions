class Solution {
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if(n > m) return "";
        
        
        // Create Hash Table for t.
        unordered_map<char, int> T;
        for(int i = 0; i < n; i++)
        {
            if(T.find(t[i]) != T.end())
                T[t[i]]++;
            else
                T[t[i]] = 1;
        }
        
        bool found = false;
        int left = 0;        
        int minLeft = -1;
        int minRight = -1;
        int minLen = INT_MAX;
        unordered_map<char, int> S;
        unordered_map<char, int> temp = T;
        for(int right = 0; right < m; right++)
        {
            // Update the S hash table.
            if(S.find(s[right]) != S.end())
                S[s[right]]++;
            else
                S[s[right]] = 1;
            
            // Keep updating the temp T map wrt s if matches are found.
            if(temp.find(s[right]) != temp.end())
            {
                temp[s[right]]--;
                
                if(temp[s[right]] == 0)
                    temp.erase(s[right]);
            }
            
            // If all t's characters are found.
            if(temp.empty())
            {
                found = true;
            // Shrink the window size from left till all t's characters are remained.
                while(left <= right)
                {
                    if(minLen > right - left + 1)
                    {
                        minLen = right - left + 1;
                        minLeft = left;
                        minRight = right;
                    }

                    S[s[left]]--;

                    left++;
                    
                    // Checking if (left, right) pair is minimum subarray.
                    int flag = 0;
                    for(auto i : T)
                    {
                        if(S[i.first] < i.second)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1)
                        break;
                }
                
                temp[s[left - 1]] = 1;
            }
        }
        
        return found == true ? s.substr(minLeft, minRight - minLeft + 1) : "";
    }
};